#pragma once

#include "../engine/GameObject.hpp"
#include <SDL_render.h>

class Platform : public GameObject {
    public:
        Platform(float x, float y, float w, float h);
        void render(Renderer* renderer) override;
    private:
        SDL_Texture* texture;
};
