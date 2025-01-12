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
    GLImageImporter *glImageImporter = static_cast<GLImageImporter*>(imageImporter);

    if (window)
    {
        window->create("Test Window", 800, 600);
        window->show();

        auto imguiLayer = MAKE_SCOPE(ImGuiLayer);
        imguiLayer->init(glfwWindow->getWindow());

        std::vector<std::string> imagePaths = {
            "fge.png",
            "awesomeface.png"
        };

        for (const auto& path : imagePaths) {
            if (!imageImporter->loadImage(path)) {
                std::cerr << "Failed to load image: " << path << std::endl;
            }
        }

        while (window->isOpen())
        {
            window->update();
            imguiLayer->begin();

            ImGui::Begin("Image Gallery");
            for (GLuint textureID : glImageImporter->getTextureIDs()) {
                ImGui::Image((void*)(intptr_t)textureID, ImVec2(200, 200));
                ImGui::Separator();
                ImGui::SameLine();
            }
            ImGui::End();

            imguiLayer->end();
        }

        window->close();
    }

    delete window;

    return 0;
}
