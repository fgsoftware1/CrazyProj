#ifndef GLIMAGEIMPORTER_HPP
#define GLIMAGEIMPORTER_HPP

#include <glad/glad.h>
#include <IL/il.h>

#include "pch.hpp"
#include "IImageImporter.hpp"

STRUCT(GLContextInfo,
    GLuint textureID;
    std::thread::id threadID;
    bool isActive;
)

DERIVED_CLASS(GLImageImporter, IImageImporter)
    FUNC_OVERRIDE(bool, loadImage, const std::string& path)
    FUNC_OVERRIDE(bool, saveImage, const std::string& path)
    FUNC_OVERRIDE(void*, getImageData)
    FUNC_OVERRIDE(bool, isLoaded)
    FUNC_OVERRIDE(void, release)

    GLuint getTextureID() const override {
        return m_TextureIDs.empty() ? 0 : m_TextureIDs.back(); // Return the last loaded texture ID
    }

    READONLY_PROPERTY(ILuint, ImageID) 
    READONLY_PROPERTY(uint32_t, Width)
    READONLY_PROPERTY(uint32_t, Height)
    READONLY_PROPERTY(uint32_t, Channels)
    PROPERTY(std::vector<GLuint>, TextureIDs)
protected:
    GLuint m_TextureID;
    std::mutex m_mutex;
    std::unordered_map<std::thread::id, GLContextInfo> m_contextMap;
    std::atomic<bool> m_isLoaded{ false };

    FUNC(GLuint, getTextureForCurrentThread)
    FUNC(void, cleanupInactiveContexts)
END_CLASS

#endif // !GLIMAGEIMPORTER_HPP