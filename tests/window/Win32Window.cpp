#include "Win32Window.h"
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0)
            ;
            return 0;
        case WM_PAINT:
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void Win32Window::createWindow(int width, int height, const char* title) {
    std::cout << "Creating Win32 window..." << std::endl;

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "Win32WindowClass";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0,
        "Win32WindowClass",
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (hwnd == NULL) {
        std::cerr << "Failed to create window" << std::endl;
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
}

void Win32Window::destroyWindow() {
    std::cout << "Destroying Win32 window..." << std::endl;
    DestroyWindow(hwnd);
}

void Win32Window::processEvents() {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        if (msg.message == WM_QUIT) {
            exit(0);
        }
    }
}
