#include "GLFWWindow.hpp"
#include "ImGuiLayer.hpp"
#include "GLImageImporter.hpp"
#include "Project.hpp"

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
    IImageImporter *imageImporter = nullptr;

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
    GLImageImporter *glImageImporter = static_cast<GLImageImporter *>(imageImporter);

    if (window)
    {
        window->create("Test Window", 800, 600);
        window->setIcon("fge.png");
        window->show();

        auto imguiLayer = MAKE_SCOPE(ImGuiLayer);
        imguiLayer->init(glfwWindow->getWindow());

        Project project("proj");
        project.createBaseFoldersAndFiles();

        std::vector<std::string> imagePaths = {
            "chai.png",
            
        };

        for (const auto &path : imagePaths)
        {
            if (!imageImporter->loadImage(path))
            {
                std::cerr << "Failed to load image: " << path << std::endl;
            }
        }

        auto textures = imageImporter->getTextureIDs();

        while (window->isOpen())
        {
            window->update();
            imguiLayer->begin();

            ImGui::Begin("Image Gallery");
            for (GLuint textureID : textures)
            {
                ImGui::Image((void *)(intptr_t)textureID, ImVec2(240, 240));
                ImGui::SameLine();
            }
            ImGui::End();

            imguiLayer->end();
        }

        window->close();
    }

    delete glfwWindow;
    delete glImageImporter;

    return 0;
}
