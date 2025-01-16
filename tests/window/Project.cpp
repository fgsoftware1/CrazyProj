#include "Project.hpp"

CTOR_IMPL_WITH_PARAMS(Project, const std::string &name)
    this->m_Name = name;
    this->m_ProjectPath = fs::path(name);
CTOR_END

DTOR_IMPL(Project)
DTOR_END

FUNC_IMPL(Project, void, createBaseFoldersAndFiles)
    if (!fs::exists(m_ProjectPath))
    {
        fs::create_directory(m_ProjectPath);
    }

    fs::path assetsPath = m_ProjectPath / "Assets";
    if (!fs::exists(assetsPath))
    {
        fs::create_directory(assetsPath);
    }

    fs::path scriptsPath = assetsPath / "Scripts";
    if (!fs::exists(scriptsPath))
    {
        fs::create_directory(scriptsPath);
    }

    std::ofstream cmakeFile((getProjectPath() / "CMakeLists.txt").string());
    if (!cmakeFile)
    {
        std::cerr << "Unable to create CMakeLists.txt file\n";
        return;
    }

    cmakeFile << "cmake_minimum_required(VERSION 3.20.0)\n";
    cmakeFile << "project(" << getProjectPath() << " LANGUAGES CXX)\n\n";
    cmakeFile << "set(CMAKE_CXX_STANDARD 17)\n\n";
    cmakeFile << "add_executable(${PROJECT_NAME} main.cpp)\n";

    cmakeFile.close();
FUNC_END