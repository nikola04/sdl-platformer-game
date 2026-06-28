#include "Renderer.hpp"

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
