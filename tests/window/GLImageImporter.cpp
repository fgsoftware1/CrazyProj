#include "GLImageImporter.hpp"

CTOR_IMPL_NO_PARAMS(GLImageImporter)
ilInit();
m_isLoaded = false;
CTOR_END

DTOR_IMPL(GLImageImporter)
release();
DTOR_END

FUNC_IMPL(GLImageImporter, bool, loadImage, const std::string& path)
std::lock_guard<std::mutex> lock(m_mutex);

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

GLuint textureID;
glGenTextures(1, &textureID);
glBindTexture(GL_TEXTURE_2D, textureID);

glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, ilGetData());
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

glGenerateMipmap(GL_TEXTURE_2D);

m_TextureIDs.push_back(textureID); // Store the texture ID
return true;
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

cleanupInactiveContexts();
m_isLoaded = false;
FUNC_END

FUNC_IMPL(GLImageImporter, GLuint, getTextureForCurrentThread)
auto threadId = std::this_thread::get_id();
auto& contextInfo = m_contextMap[threadId];

if (!contextInfo.isActive) {
    glGenTextures(1, &contextInfo.textureID);
    contextInfo.threadID = threadId;
    contextInfo.isActive = true;
}

return contextInfo.textureID;
FUNC_END

FUNC_IMPL(GLImageImporter, void, cleanupInactiveContexts)
for (auto it = m_contextMap.begin(); it != m_contextMap.end();) {
    if (it->second.isActive) {
        glDeleteTextures(1, &it->second.textureID);
        it = m_contextMap.erase(it);
    }
    else {
        ++it;
    }
}
FUNC_END
