#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

class Input {
    public:
        void begindFrame();
        void handleEvent(SDL_Event& e);
        bool isHeld(SDL_Keycode key);
        bool isPressed(SDL_Keycode key);
        bool isReleased(SDL_Keycode key);

    private:
        std::unordered_map<SDL_Keycode, bool> current, previous;
};
