#include "Renderer.hpp"
#include <cstdio>

Renderer::Renderer(SDL_Window* window, int width, int height) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        printf("Renderer error: %s", SDL_GetError());
        return;
    }
    SDL_RenderSetLogicalSize(renderer, width, height);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::get() {
    return renderer;
}

void Renderer::printRendererInfo() {
    SDL_RendererInfo info;
    if (SDL_GetRendererInfo(renderer, &info) == 0) {
        printf("Using GPU Driver: %s\n", info.name);
    }
}
