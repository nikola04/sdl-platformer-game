cmake_minimum_required(VERSION 3.20)

project(SDLGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(
    game
    src/main.cpp
    src/engine/Engine.cpp
    src/engine/PhysicsSystem.cpp
    src/engine/Input.cpp
    src/engine/Renderer.cpp
    src/engine/Window.cpp
    src/engine/ResourceManager.cpp
    src/game/Background.cpp
    src/game/Platform.cpp
    src/game/Player.cpp
)

target_include_directories(
    game PRIVATE
    /opt/homebrew/opt/sdl2/include
    /opt/homebrew/opt/sdl2_image/include
)

target_link_directories(
    game PRIVATE
    /opt/homebrew/opt/sdl2/lib
)

target_link_libraries(game SDL2::SDL2 SDL2_image::SDL2_image)

target_compile_definitions(game PRIVATE ASSETS_PATH="${CMAKE_SOURCE_DIR}/assets/")
