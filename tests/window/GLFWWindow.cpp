#include "GLFWWindow.h"
#include <iostream>

void GLFWWindow::createWindow(int width, int height, const char* title) {
    std::cout << "Creating GLFW window..." << std::endl;
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
}

void GLFWWindow::destroyWindow() {
    std::cout << "Destroying GLFW window..." << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GLFWWindow::processEvents() {
    glfwPollEvents();
    if (glfwWindowShouldClose(window)) {
        exit(0);
    }
}
