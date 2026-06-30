#include "Background.hpp"
#include "../engine/ResourceManager.hpp"
#include "../engine/Config.hpp"

Background::Background(): GameObject(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, false) {
    texture = ResourceManager::get().load(ASSETS_PATH "background/level1_classic.png");
}

void Background::render(Renderer* renderer) {
    SDL_Rect dest = { (int)x, (int)y, (int)w, (int)h };

    SDL_RenderCopy(renderer->get(), texture, nullptr, &dest);
}
