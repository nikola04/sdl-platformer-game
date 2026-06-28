#pragma once
#include "../engine/GameObject.hpp"


class Background : public GameObject {
    public:
        Background();
        void render(Renderer* renderer) override;
    private:
        SDL_Texture* texture;
};
