cmake_minimum_required(VERSION 3.20.0)
project(Crazy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui-node-editor)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/ImNodes
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(Crazy ${CMAKE_CURRENT_SOURCE_DIR}/Crazy.cpp)
target_precompile_headers(Crazy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)
target_link_libraries(Crazy PRIVATE imnodes)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)