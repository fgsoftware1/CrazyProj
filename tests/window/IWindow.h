#ifndef IWINDOW_H
#define IWINDOW_H

class IWindow {
public:
    virtual ~IWindow() {}
    virtual void createWindow(int width, int height, const char* title) = 0;
    virtual void destroyWindow() = 0;
    virtual void processEvents() = 0;
};

#endif // IWINDOW_H
