#include "GLADRenderer.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void GLADRenderer::initialize() {
    std::cout << "Initializing GLAD for OpenGL..." << std::endl;
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }
    // Set up OpenGL state here
}

void GLADRenderer::renderFrame() {
    std::cout << "Rendering frame with GLAD..." << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);
    // Add rendering code here
}

void GLADRenderer::shutdown() {
    std::cout << "Shutting down GLAD..." << std::endl;
    // Cleanup code here
}
