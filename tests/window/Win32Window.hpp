#ifndef WIN32WINDOW_HPP
#define WIN32WINDOW_HPP

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "pch.hpp"
#include "IWindow.hpp"

DERIVED_CLASS(Win32Window, IWindow)
    FUNC_OVERRIDE(void, create, const char* title, int width, int height)
    FUNC_OVERRIDE(void, show)
    FUNC_OVERRIDE(void, close)
    FUNC_OVERRIDE(void, update)
    FUNC_CONST_OVERRIDE(bool, isOpen)

    READONLY_PROPERTY(HWND, Window)
    READONLY_PROPERTY(HINSTANCE, Instance)
    READONLY_PROPERTY(bool, isOpen)
END_CLASS

#endif