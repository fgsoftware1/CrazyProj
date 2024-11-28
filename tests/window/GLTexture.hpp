#ifndef GLTEXTURE_HPP
#define GLTEXTURE_HPP

#include <glad/glad.h>

#include "pch.hpp"
#include "ITexture.hpp"

DERIVED_CLASS(GLTexture, ITexture)
    PROPERTY(GLuint, textureID)
    PROPERTY(GLuint, width)
    PROPERTY(GLuint, height)
    PROPERTY(GLuint, channels)

    FUNC_OVERRIDE(void, Create, const fs::path& path)
    FUNC_OVERRIDE(void, Create, uint32_t width, uint32_t height, const void* data)
    FUNC_CONST_OVERRIDE(void, Bind, unsigned int slot = 0)
    FUNC_CONST_OVERRIDE(void, Unbind)

    FUNC_CONST_OVERRIDE(GLuint, GetWidth)
    FUNC_CONST_OVERRIDE(GLuint, GetHeight) 
    FUNC_CONST_OVERRIDE(GLuint, GetChannels)
    FUNC_CONST_OVERRIDE(GLuint, GetRendererID)
END_CLASS

#endif // GLTEXTURE_HPP