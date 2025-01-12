#include "Win32Window.hpp"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

CTOR_IMPL_NO_PARAMS(Win32Window)
    m_Window = nullptr;
    m_Instance = nullptr;
    m_isOpen = false;
CTOR_END

DTOR_IMPL(Win32Window)
    close();
DTOR_END

FUNC_IMPL(Win32Window, void, create, const char* title, int width, int height)
    m_Instance = GetModuleHandle(nullptr);
    
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_Instance;
    wc.lpszClassName = "Win32WindowClass";
    
    RegisterClassEx(&wc);
    
    m_Window = CreateWindowEx(
        0,
        "Win32WindowClass",
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        nullptr,
        nullptr,
        m_Instance,
        nullptr
    );
    
    m_isOpen = true;
FUNC_END

FUNC_IMPL(Win32Window, void, show)
    ShowWindow(m_Window, SW_SHOW);
FUNC_END

FUNC_IMPL(Win32Window, void, close)
    if (m_Window) {
        DestroyWindow(m_Window);
        m_Window = nullptr;
    }
    m_isOpen = false;
FUNC_END

FUNC_IMPL(Win32Window, void, update)
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        
        if (msg.message == WM_QUIT) {
            m_isOpen = false;
        }
    }
FUNC_END

FUNC_IMPL_CONST(Win32Window, bool, isOpen)
    return m_isOpen;
FUNC_END

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}