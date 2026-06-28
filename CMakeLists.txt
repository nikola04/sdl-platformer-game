cmake_minimum_required(VERSION 3.20)

project(SDLGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

add_executable(
    game
    src/main.cpp
    src/engine/Engine.cpp
    src/engine/Renderer.cpp
    src/engine/Window.cpp
    src/game/Square.cpp
)

target_include_directories(
    game PRIVATE
    /opt/homebrew/opt/sdl2/include
)

target_link_directories(
    game PRIVATE
    /opt/homebrew/opt/sdl2/lib
)

target_link_libraries(
    game
    SDL2::SDL2
)
