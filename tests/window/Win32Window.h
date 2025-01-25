#ifndef WIN32_WINDOW_H
#define WIN32_WINDOW_H

#include "IWindow.h"
#include <Windows.h>

class Win32Window : public IWindow {
public:
    void createWindow(int width, int height, const char* title) override;
    void destroyWindow() override;
    void processEvents() override;

private:
    HWND hwnd;
};

#endif // WIN32_WINDOW_H
