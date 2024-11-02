#include "GLFWWindow.hpp"

enum class WindowType {
    Win32,
    GLFW,
    SDL
};

int main(){
    WindowType windowType = WindowType::GLFW;
    IWindow* window = nullptr;

    switch (windowType) {
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

    if (window) {
        window->create("Test Window", 800, 600);
        window->show();

        while (window->isOpen()) {
            window->update();
        }

        window->close();
        delete window;
    }

    return 0;
}