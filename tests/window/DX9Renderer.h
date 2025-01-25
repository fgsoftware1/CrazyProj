#ifndef DX9_RENDERER_H
#define DX9_RENDERER_H

#include "IRenderer.h"

class DX9Renderer : public IRenderer {
public:
    void initialize() override;
    void renderFrame() override;
    void shutdown() override;
};

#endif // DX9_RENDERER_H
