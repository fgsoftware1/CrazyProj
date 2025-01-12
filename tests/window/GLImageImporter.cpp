#include "GLImageImporter.hpp"

CTOR_IMPL_NO_PARAMS(GLImageImporter)
    ilInit(); // Initialize DevIL
CTOR_END

DTOR_IMPL(GLImageImporter)
    if(m_TextureID != 0) {
        glDeleteTextures(1, &m_TextureID);
    }
    if(m_ImageID != 0) {
        ilDeleteImages(1, &m_ImageID);
    }
DTOR_END

FUNC_IMPL(GLImageImporter, bool, loadImage, const std::string& path)
    ilGenImages(1, &m_ImageID);
    ilBindImage(m_ImageID);

    if (!ilLoadImage(path.c_str())) {
        ilDeleteImages(1, &m_ImageID);
        return false;
    }

    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    
    m_Width = ilGetInteger(IL_IMAGE_WIDTH);
    m_Height = ilGetInteger(IL_IMAGE_HEIGHT);
    m_Channels = ilGetInteger(IL_IMAGE_CHANNELS);

    // Create OpenGL texture
    glGenTextures(1, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, ilGetData());

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return true;
FUNC_END

FUNC_IMPL(GLImageImporter, bool, saveImage, const std::string& path)
    if(m_ImageID == 0) return false;
    ilBindImage(m_ImageID);
    return ilSaveImage(path.c_str());
FUNC_END

FUNC_IMPL(GLImageImporter, void*, getImageData)
    return ilGetData();
FUNC_END