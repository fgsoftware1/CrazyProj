#ifndef GLFWWINDOW_HPP
#define GLFWWINDOW_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "IWindow.hpp"

DERIVED_CLASS(GLFWWindow, IWindow)
    FUNC_OVERRIDE(void, create, const char* title, int width, int height)
    FUNC_OVERRIDE(void, show)
    FUNC_OVERRIDE(void, close)
    FUNC_OVERRIDE(void, update)
    FUNC_CONST_OVERRIDE(bool, isOpen)

    READONLY_PROPERTY(GLFWwindow*, window)
END_CLASS

#endif