#include "GLFWWindow.hpp"
#include "ImGuiLayer.hpp"

enum class WindowType
{
    Win32,
    GLFW,
    SDL
};

int main()
{
    WindowType windowType = WindowType::GLFW;
    IWindow *window = nullptr;

    switch (windowType)
    {
    // case WindowType::Win32:
    //     window = new Win32Window();
    //     break;
    case WindowType::GLFW:
        window = new GLFWWindow();
        break;
        // case WindowType::SDL:
        //     window = new SDLWindow();
        //     break;
    }

    GLFWWindow *glfwWindow = static_cast<GLFWWindow *>(window);

    if (window)
    {
        window->create("Test Window", 800, 600);
        window->show();

        auto imguiLayer = MAKE_SCOPE(ImGuiLayer);
        imguiLayer->init(glfwWindow->get_window());

        while (window->isOpen())
        {
            window->update();
            imguiLayer->begin();

            ImGui::Begin("Example Window");
            ImGui::Text("Hello, Docking!");
            ImGui::End();

            imguiLayer->end();
        }

        window->close();
    }

    delete window;

    return 0;
}
