#include "GLFWWindow.hpp"

CTOR_IMPL_WITH_PARAMS(GLFWWindow, m_window(nullptr))
if (!glfwInit())
    exit(EXIT_FAILURE);

glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
CTOR_END

DTOR_IMPL(GLFWWindow)
close();
glfwTerminate();
DTOR_END

FUNC_IMPL(GLFWWindow, void, create, const char *title, int width, int height)
m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
if (!m_window)
{
    glfwTerminate();
    std::cerr << "Can't initialize glfw!" << std::endl;
    exit(EXIT_FAILURE);
}
FUNC_END

FUNC_IMPL(GLFWWindow, void, show)
glfwMakeContextCurrent(m_window);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
    std::cerr << "Can't initialize glad!" << std::endl;
    glfwTerminate();
}
FUNC_END

FUNC_IMPL(GLFWWindow, void, close)
glfwDestroyWindow(m_window);
FUNC_END

FUNC_IMPL(GLFWWindow, void, update)
if (m_window)
{
    glfwPollEvents();
}
FUNC_END

FUNC_IMPL_CONST(GLFWWindow, bool, isOpen)
return m_window != nullptr && !glfwWindowShouldClose(m_window);
FUNC_END