#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include "IWindow.h"
#include <GLFW/glfw3.h>

class GLFWWindow : public IWindow {
public:
    void createWindow(int width, int height, const char* title) override;
    void destroyWindow() override;
    void processEvents() override;

private:
    GLFWwindow* window;
};

#endif // GLFW_WINDOW_H
