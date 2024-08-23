cmake_minimum_required(VERSION 3.20.0)
project(tests LANGUAGES CXX)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE lib_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#add_library(tests ${lib_SRC})
#target_precompile_headers(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)

add_executable(Crazy ${CMAKE_CURRENT_SOURCE_DIR}/Crazy.cpp)