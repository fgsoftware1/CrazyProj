#ifndef GLIMAGEIMPORTER_HPP
#define GLIMAGEIMPORTER_HPP

#include <glad/glad.h>
#include <IL/il.h>
#include <IL/ilu.h>

#include "pch.hpp"
#include "IImageImporter.hpp"

DERIVED_CLASS(GLImageImporter, IImageImporter)
    FUNC_OVERRIDE(bool, loadImage, const std::string& path)
    FUNC_OVERRIDE(bool, saveImage, const std::string& path)
    FUNC_OVERRIDE(void*, getImageData)
    FUNC_OVERRIDE(bool, isLoaded)
    FUNC_OVERRIDE(void, release)
    FUNC_OVERRIDE(void, clearTextures)

    std::vector<unsigned int> getTextureIDs() const override {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_TextureIDs;
    }

protected:
    mutable std::mutex m_mutex;
    std::vector<GLuint> m_TextureIDs;
    std::atomic<bool> m_isLoaded{false};
    ILuint m_ImageID{0};
    
    FUNC(bool, generateTexture, const unsigned char* data, int width, int height)
END_CLASS


#endif // !GLIMAGEIMPORTER_HPP