#include "GLFWWindow.hpp"
#include "ImGuiLayer.hpp"
#include "GLImageImporter.hpp"

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
	IImageImporter* imageImporter = nullptr;

    switch (windowType)
    {
    // case WindowType::Win32:
    //     window = new Win32Window();
    //     break;
    case WindowType::GLFW:
        window = new GLFWWindow();
		imageImporter = new GLImageImporter();
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
        imguiLayer->init(glfwWindow->getWindow());

        GLuint texture1 = imageImporter->loadImage("fge.png");
        if (texture1 == 0) {
            return -1; // Failed to load the texture
        }

        while (window->isOpen())
        {
            window->update();
            imguiLayer->begin();

            ImGui::Begin("Example Window");
            ImGui::Text("Hello, Docking!");
			ImGui::Image((void*)(intptr_t)texture1, ImVec2(500, 500));
            ImGui::End();

            imguiLayer->end();
        }

        window->close();
    }

    delete window;

    return 0;
}
