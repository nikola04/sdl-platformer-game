#include "Platform.hpp"
#include "../engine/ResourceManager.hpp"

Platform::Platform(float x, float y, float w, float h): GameObject(x, y, w, h) {
    texture = ResourceManager::get().load(ASSETS_PATH "platform.png");
}

void Platform::render(Renderer* renderer) {
    SDL_Rect src = { 0, 0, 190, 190 };
    SDL_Rect dest = { (int)x, (int)y, (int)w, (int)h };

    SDL_RenderCopy(renderer->get(), texture, &src, &dest);
}
