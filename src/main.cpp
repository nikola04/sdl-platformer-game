#include "engine/Engine.hpp"
#include "engine/Config.hpp"
#include "game/Background.hpp"
#include "game/Platform.hpp"
#include "game/Player.hpp"
#include <SDL.h>
#include <memory>

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    Engine engine;
    engine.addObject(std::make_unique<Background>());
    engine.addObject(std::make_unique<Platform>(100, WINDOW_HEIGHT - 70, 300, 50));
    engine.addObject(std::make_unique<Platform>(550, WINDOW_HEIGHT - 270, 100, 50));
    engine.addObject(std::make_unique<Platform>(500, WINDOW_HEIGHT - 470, 100, 50));
    engine.addObject(std::make_unique<Platform>(125, 150, 50, 50));
    engine.addObject(std::make_unique<Player>());
    engine.run();

    SDL_Quit();
    return 0;
}
