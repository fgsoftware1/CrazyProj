#ifndef GLIMAGEIMPORTER_HPP
#define GLIMAGEIMPORTER_HPP

#include <glad/glad.h>
#include <IL/il.h>

#include "pch.hpp"
#include "IImageImporter.hpp"

DERIVED_CLASS(GLImageImporter, IImageImporter)
    FUNC_OVERRIDE(bool, loadImage, const std::string& path)
    FUNC_OVERRIDE(bool, saveImage, const std::string& path)
    FUNC_OVERRIDE(void*, getImageData)

    READONLY_PROPERTY(ILuint, ImageID);
    READONLY_PROPERTY(GLuint, TextureID);
    READONLY_PROPERTY(uint32_t, Width);
    READONLY_PROPERTY(uint32_t, Height);
    READONLY_PROPERTY(uint32_t, Channels);
END_CLASS

#endif // !GLIMAGEIMPORTER_HPP