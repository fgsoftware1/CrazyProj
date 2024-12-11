#ifndef IMGUILAYER_HPP
#define IMGUILAYER_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include "pch.hpp"

CLASS(ImGuiLayer)
    PROPERTY(bool, dockspaceOpen)
    PROPERTY(bool, opt_fullscreen)
    PROPERTY(bool, opt_padding)
    PROPERTY(ImGuiDockNodeFlags, dockspace_flags)
    PROPERTY(ImGuiWindowFlags, window_flags)
    READONLY_PROPERTY(GLFWwindow*, window)

    FUNC(void, init, GLFWwindow* window);
    FUNC(void, shutdown, );
    FUNC(void, begin, );
    FUNC(void, end, );

    FUNC(void, beginDockspace, );
    FUNC(void, endDockspace, );
    
    protected:
        FUNC(void, setupDockspaceMenuBar, );
END_CLASS

#endif