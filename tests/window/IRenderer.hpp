#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include "pch.hpp"

INTERFACE(Renderer)
    FUNC_VIRTUAL(bool, Initialize);
    FUNC_VIRTUAL(void, Cleanup);

    FUNC_VIRTUAL(void, CreateBuffer);
    FUNC_VIRTUAL(void, DeleteBuffer);
    FUNC_VIRTUAL(void, BindBuffer);
    FUNC_VIRTUAL(void, UpdateBuffer);

    FUNC_VIRTUAL(void, SetViewport, int x, int y, int width, int height);
    FUNC_VIRTUAL(void, SetBlendMode, bool enable);
    FUNC_VIRTUAL(void, SetDepthTest, bool enable);
    FUNC_VIRTUAL(void, Clear);

    FUNC_VIRTUAL(void, DrawTriangle);
    FUNC_VIRTUAL(void, DrawQuad);
    FUNC_VIRTUAL(void, DrawLine, float x1, float y1, float x2, float y2);
    FUNC_VIRTUAL(void, DrawSprite);

    FUNC_VIRTUAL(void, CreateTexture);
    FUNC_VIRTUAL(void, DeleteTexture);
    FUNC_VIRTUAL(void, BindTexture);
    FUNC_VIRTUAL(void, UpdateTexture);
END_INTERFACE

#endif // IRENDERER_HPP