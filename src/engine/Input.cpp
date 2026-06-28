#include "Input.hpp"

void Input::begindFrame() {
    previous = current;
}

void Input::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) current[e.key.keysym.sym] = true;
    if (e.type == SDL_KEYUP)   current[e.key.keysym.sym] = false;
}

bool Input::isHeld(SDL_Keycode key) {
    return current[key];
}

bool Input::isPressed(SDL_Keycode key) {
    return current[key] && !previous[key];
}

bool Input::isReleased(SDL_Keycode key) {
    return !current[key] && previous[key];
}
