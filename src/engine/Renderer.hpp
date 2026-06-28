#pragma once

#include <SDL2/SDL.h>

class Renderer {
    public:
        Renderer(SDL_Window* window);

        ~Renderer();

        void clear();
        void present();

        SDL_Renderer* get();


    private:
        SDL_Renderer* renderer;
};
