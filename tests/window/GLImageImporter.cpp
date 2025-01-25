#include "GLImageImporter.hpp"

CTOR_IMPL_NO_PARAMS(GLImageImporter)
ilInit();
m_isLoaded = false;
CTOR_END

DTOR_IMPL(GLImageImporter)
DTOR_END

FUNC_IMPL(GLImageImporter, bool, loadImage, const std::string& path)
    std::lock_guard<std::mutex> lock(m_mutex);
    
    ILuint imageID;
    ilGenImages(1, &imageID);
    ilBindImage(imageID);

    if (!ilLoadImage(path.c_str())) {
        ILenum error = ilGetError();
        std::cerr << "Error loading file: " << iluErrorString(error) << std::endl;
        ilDeleteImages(1, &imageID);
        return false;
    }

    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    
    ILint width = ilGetInteger(IL_IMAGE_WIDTH);
    ILint height = ilGetInteger(IL_IMAGE_HEIGHT);
    ILint format = ilGetInteger(IL_IMAGE_FORMAT);
    ILubyte* data = ilGetData();

    bool success = generateTexture(data, width, height);
    
    ilDeleteImages(1, &imageID);
    return success;
FUNC_END

FUNC_IMPL(GLImageImporter, bool, generateTexture, const unsigned char* data, int width, int height)
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    m_TextureIDs.push_back(textureID);
    m_isLoaded = true;
    return true;
FUNC_END

FUNC_IMPL(GLImageImporter, void, clearTextures)
    std::lock_guard<std::mutex> lock(m_mutex);
    for(GLuint id : m_TextureIDs) {
        glDeleteTextures(1, &id);
    }
    m_TextureIDs.clear();
    m_isLoaded = false;
FUNC_END
FUNC_IMPL(GLImageImporter, bool, saveImage, const std::string & path)
std::lock_guard<std::mutex> lock(m_mutex);
if (!m_isLoaded || m_ImageID == 0) return false;

ilBindImage(m_ImageID);
return ilSaveImage(path.c_str());
FUNC_END

FUNC_IMPL(GLImageImporter, void*, getImageData)
std::lock_guard<std::mutex> lock(m_mutex);
if (!m_isLoaded) return nullptr;
    return ilGetData();
FUNC_END

FUNC_IMPL(GLImageImporter, bool, isLoaded)
return m_isLoaded.load();
FUNC_END

FUNC_IMPL(GLImageImporter, void, release)
std::lock_guard<std::mutex> lock(m_mutex);

if (m_ImageID != 0) {
    ilDeleteImages(1, &m_ImageID);
    m_ImageID = 0;
}
m_isLoaded = false;
FUNC_END
