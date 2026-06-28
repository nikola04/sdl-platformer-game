#include "Window.hpp"

Window::Window(const char* title, int widht, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widht, height, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

SDL_Window* Window::get() {
    return window;
}
