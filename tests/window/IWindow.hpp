#ifndef IWINDOW_HPP
#define IWINDOW_HPP

#include "pch.hpp"

INTERFACE(Window)
    FUNC_VIRTUAL(void, create, const char* title, int width, int height)
    FUNC_VIRTUAL(void, show)
    FUNC_VIRTUAL(void, close)
    FUNC_VIRTUAL(void, update)
    FUNC_VIRTUAL(void, setIcon, const char* iconPath)
    FUNC_CONST_VIRTUAL(bool, isOpen)
END_INTERFACE

#endif