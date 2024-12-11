cmake_minimum_required(VERSION 3.20.0)
project(CrazyTests LANGUAGES CXX)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(sdl2 CONFIG REQUIRED)
find_package(DevIL)

file(GLOB_RECURSE CAR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/car/*.cpp)
file(GLOB_RECURSE WINDOW_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/window/*.cpp)

add_executable(CarTests ${CAR_SOURCES})
target_precompile_headers(CarTests REUSE_FROM Crazy)
target_include_directories(CarTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/car)

add_executable(WindowTests ${WINDOW_SOURCES})
target_compile_definitions(WindowTests PRIVATE -DGLFW_INCLUDE_NONE)
target_precompile_headers(WindowTests REUSE_FROM Crazy)
target_include_directories(WindowTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/window
)
target_link_libraries(WindowTests PRIVATE glad::glad glfw imgui::imgui ${IL_LIBRARIES} unofficial::imgui-node-editor::imgui-node-editor)