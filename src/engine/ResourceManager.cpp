#include "ResourceManager.hpp"
#include <SDL_image.h>
#include <SDL_render.h>

void ResourceManager::init(SDL_Renderer* renderer) {
    this->renderer = renderer;
    IMG_Init(IMG_INIT_PNG);
}

SDL_Texture* ResourceManager::load(const std::string& path) {
    if (cache.count(path)) return cache[path];

    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    cache[path] = texture;
    return texture;
}
