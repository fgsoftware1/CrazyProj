#ifndef ITEXTURE_HPP
#define ITEXTURE_HPP

#include "pch.hpp"

INTERFACE(Texture)
    FUNC_VIRTUAL(void, Create, const fs::path& path);
    FUNC_VIRTUAL(void, Create, uint32_t width, uint32_t height, const void* data);
    FUNC_CONST_VIRTUAL(void, Bind, uint32_t slot = 0);
    FUNC_CONST_VIRTUAL(void, Unbind);

    FUNC_CONST_VIRTUAL(uint32_t, GetWidth);
    FUNC_CONST_VIRTUAL(uint32_t, GetHeight);
    FUNC_CONST_VIRTUAL(uint32_t, GetChannels);
    FUNC_CONST_VIRTUAL(uint32_t, GetRendererID);
END_INTERFACE

#endif // ITEXTURE_HPP