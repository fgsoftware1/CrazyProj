#ifndef PROJECT_HPP
#define PROJECT_HPP

#include "pch.hpp"

namespace fs = std::filesystem;

CLASS(Project)
    CTOR(Project, const std::string& name)

    FUNC(void, createBaseFoldersAndFiles)

    READONLY_PROPERTY(std::string, Name)
    READONLY_PROPERTY(fs::path, ProjectPath)
END_CLASS

#endif // !PROJECT_HPP