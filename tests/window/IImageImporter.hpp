#ifndef IIMAGEIMPORTER_HPP
#define IIMAGEIMPORTER_HPP

#include "pch.hpp"

class IImageImporter {
public: virtual ~IImageImporter() = default;
virtual bool loadImage(const std::string& path) = 0;
virtual bool saveImage(const std::string& path) = 0;
virtual void* getImageData() = 0;
};

#endif // !IIMAGEIMPORTER_HPP