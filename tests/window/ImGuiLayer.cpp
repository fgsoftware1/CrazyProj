#include "ImGuiLayer.hpp"

CTOR_IMPL_NO_PARAMS(ImGuiLayer)
    this->m_dockspaceOpen = true;
    this->m_opt_fullscreen = true; 
    this->m_opt_padding = false;
    this->m_dockspace_flags = ImGuiDockNodeFlags_None;
    this->m_window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    this->m_window = nullptr;
CTOR_END

DTOR_IMPL(ImGuiLayer)
    shutdown();
DTOR_END

FUNC_IMPL(ImGuiLayer, void, init, GLFWwindow* window)
    m_window = window;
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");
FUNC_END

FUNC_IMPL(ImGuiLayer, void, shutdown)
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
FUNC_END

FUNC_IMPL(ImGuiLayer, void, begin)
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    beginDockspace();
FUNC_END

FUNC_IMPL(ImGuiLayer, void, end)
    endDockspace();
    
    ImGuiIO& io = ImGui::GetIO();
    int display_w, display_h;
    glfwGetFramebufferSize(m_window, &display_w, &display_h);
    io.DisplaySize = ImVec2((float)display_w, (float)display_h);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
FUNC_END

FUNC_IMPL(ImGuiLayer, void, beginDockspace)
    if (m_opt_fullscreen)
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        m_window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                         ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                         ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else
    {
        m_dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    if (m_dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        m_window_flags |= ImGuiWindowFlags_NoBackground;

    if (!m_opt_padding)
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    
    ImGui::Begin("DockSpace Demo", &m_dockspaceOpen, m_window_flags);
    
    if (!m_opt_padding)
        ImGui::PopStyleVar();
    if (m_opt_fullscreen)
        ImGui::PopStyleVar(2);

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), m_dockspace_flags);
    }
    
    setupDockspaceMenuBar();
FUNC_END

FUNC_IMPL(ImGuiLayer, void, endDockspace)
    ImGui::End();
FUNC_END

FUNC_IMPL(ImGuiLayer, void, setupDockspaceMenuBar)
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Options"))
        {
            ImGui::MenuItem("Fullscreen", NULL, &m_opt_fullscreen);
            ImGui::MenuItem("Padding", NULL, &m_opt_padding);
            ImGui::Separator();
            
            if (ImGui::MenuItem("Close")) 
                m_dockspaceOpen = false;
                
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
FUNC_END