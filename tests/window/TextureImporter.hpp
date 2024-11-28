#ifndef TETXURE_IMPORTER_HPP
#define TETXURE_IMPORTER_HPP

#include "pch.hpp"
#include "GLTexture.hpp"

ENUM_CLASS(TextureFormat,
    RGB8,
    RGBA8,
    RGB16F,
    RGBA16F,
    RGB32F,
    RGBA32F,
    SRGB8,
    SRGBA8
)

ENUM_CLASS(TextureType,
    TEXTURE_2D,
    TEXTURE_3D,
    TEXTURE_CUBE_MAP,
    TEXTURE_2D_ARRAY
)

ENUM_CLASS(ImageFileFormat,
    PNG,
    EXR,
    TIFF
)

ENUM_CLASS(TextureCompression,
    NONE,
    // PNG compression
    PNG_DEFLATE,
    // EXR compression
    EXR_PIZ,
    EXR_ZIP,
    EXR_RLE,
    // TIFF compression
    TIFF_LZW,
    TIFF_ZIP,
    //!JPEG
    TIFF_DCT 
)

struct TextureProperties {
    bool generateMipmaps = true;
    uint32_t maxAnisotropy = 16;
    bool sRGB = false;
    bool flipVertically = true;
    TextureFormat format = TextureFormat::RGBA8;
    TextureType type = TextureType::TEXTURE_2D;
    TextureCompression compression = TextureCompression::NONE;
};

CLASS(TextureImporter)
    PROPERTY(uint32_t, Width)
    PROPERTY(uint32_t, Height)
    PROPERTY(uint32_t, Channels)
    PROPERTY(TextureProperties, Properties)

    FUNC(bool, LoadFromFile, const fs::path& filePath, TextureProperties properties = TextureProperties())
    FUNC(bool, SaveToFile, const fs::path& filePath, ImageFileFormat format, TextureCompression compression = TextureCompression::NONE)

    FUNC_INLINE_CONST(uint32_t, GetWidth, return m_Width) 
    FUNC_INLINE_CONST(uint32_t, GetHeight, return m_Height)
    FUNC_INLINE_CONST(uint32_t, GetChannels, return m_Channels) 
    FUNC_INLINE_CONST(TextureFormat, GetFormat, return m_Properties.format)
    FUNC_INLINE_CONST(TextureType, GetType, return m_Properties.type) 
END_CLASS

#endif // TETXURE_IMPORTER_HPP