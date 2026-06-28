#include "engine/Engine.hpp"
#include "game/Square.hpp"
#include <SDL.h>
#include <memory>

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    Engine engine;
    engine.addObject(std::make_unique<Square>());
    engine.run();

    SDL_Quit();
    return 0;
}
