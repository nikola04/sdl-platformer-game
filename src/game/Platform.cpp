#include "Platform.hpp"

Platform::Platform() {
    x = 50;
    y = 550;
    w = 500;
    h = 30;
}

void Platform::render(Renderer* renderer) {
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer->get(), 110, 255, 145, 255);

    SDL_RenderFillRect(renderer->get(), &rect);
}
