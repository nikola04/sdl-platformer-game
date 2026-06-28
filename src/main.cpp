#include "engine/Engine.hpp"
#include "game/Platform.hpp"
#include "game/Player.hpp"
#include <SDL.h>
#include <memory>

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    Engine engine;
    engine.addObject(std::make_unique<Platform>());
    engine.addObject(std::make_unique<Player>());
    engine.run();

    SDL_Quit();
    return 0;
}
