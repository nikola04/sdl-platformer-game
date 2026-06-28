#pragma once

#include <SDL2/SDL.h>

class Renderer {
    public:
        Renderer(SDL_Window* window, int width, int height);

        ~Renderer();

        void clear();
        void present();
        void printRendererInfo();

        SDL_Renderer* get();


    private:
        SDL_Renderer* renderer;
};
