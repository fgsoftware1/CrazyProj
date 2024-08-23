#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "pch.hpp"

CLASS(CrazyWindow)

READONLY_PROPERTY(GLFWwindow*, window)
PROPERTY(int, width)
PROPERTY(int, height)
PROPERTY(std::string, title)
PROPERTY(bool, vsync)



END_CLASS