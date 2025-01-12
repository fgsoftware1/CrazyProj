#include "GLFWWindow.hpp"

CTOR_IMPL_WITH_PARAMS(GLFWWindow, m_Window(nullptr))
if (!glfwInit())
    exit(EXIT_FAILURE);

glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
CTOR_END

DTOR_IMPL(GLFWWindow)
close();
glfwTerminate();
DTOR_END

FUNC_IMPL(GLFWWindow, void, create, const char *title, int width, int height)
m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
if (!m_Window)
{
    glfwTerminate();
    std::cerr << "Can't initialize glfw!" << std::endl;
    exit(EXIT_FAILURE);
}
FUNC_END

FUNC_IMPL(GLFWWindow, void, show)
glfwMakeContextCurrent(m_Window);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
    std::cerr << "Can't initialize glad!" << std::endl;
    glfwTerminate();
}
FUNC_END

FUNC_IMPL(GLFWWindow, void, close)
glfwDestroyWindow(m_Window);
FUNC_END

FUNC_IMPL(GLFWWindow, void, update)
if (m_Window)
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
FUNC_END

FUNC_IMPL_CONST(GLFWWindow, bool, isOpen)
return m_Window != nullptr && !glfwWindowShouldClose(m_Window);
FUNC_END