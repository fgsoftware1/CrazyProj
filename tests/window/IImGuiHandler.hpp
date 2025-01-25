#ifndef IIMGUIHANDLER_HPP
#define IIMGUIHANDLER_HPP

#include "imgui.h"

class IImGuiHandler {
public:
    virtual ~IImGuiHandler() = default;
    virtual void init(void* window) = 0;
    virtual void shutdown() = 0;
    virtual void newFrame() = 0;
};

#endif // IIMGUIHANDLER_HPP
