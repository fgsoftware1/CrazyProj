#ifndef IIMAGEIMPORTER_HPP
#define IIMAGEIMPORTER_HPP

#include "pch.hpp"

INTERFACE(ImageImporter)
	FUNC_VIRTUAL(bool, loadImage, const std::string& path)
	FUNC_VIRTUAL(bool, saveImage, const std::string& path)
	FUNC_VIRTUAL(void*, getImageData)
	FUNC_VIRTUAL(bool, isLoaded)
	FUNC_VIRTUAL(void, release)
	FUNC_CONST_VIRTUAL(std::vector<unsigned int>, getTextureIDs)
	FUNC_VIRTUAL(void, clearTextures)
END_INTERFACE
#endif // !IIMAGEIMPORTER_HPP