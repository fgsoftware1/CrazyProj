#ifndef GLAD_RENDERER_H
#define GLAD_RENDERER_H

#include "IRenderer.h"

class GLADRenderer : public IRenderer {
public:
    void initialize() override;
    void renderFrame() override;
    void shutdown() override;
};

#endif // GLAD_RENDERER_H
