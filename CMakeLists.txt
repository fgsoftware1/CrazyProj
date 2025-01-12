cmake_minimum_required(VERSION 3.20.0)
project(Crazy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/build/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(Crazy ${CMAKE_CURRENT_SOURCE_DIR}/Crazy.cpp)
target_precompile_headers(Crazy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)