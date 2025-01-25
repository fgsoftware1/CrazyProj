#ifndef IRENDERER_H
#define IRENDERER_H

class IRenderer {
public:
    virtual ~IRenderer() {}
    virtual void initialize() = 0;
    virtual void renderFrame() = 0;
    virtual void shutdown() = 0;
};

#endif // IRENDERER_H
