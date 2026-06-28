#pragma once

#include "../engine/GameObject.hpp"
#include <SDL_render.h>
#include <vector>

class Player : public GameObject {
    private:
        RigidBody rb;
        bool doubleJumped;
        std::vector<SDL_Texture*> walkFrames;
        float frameTimer = 0.0;
        int currentFrame = 0;
        bool facingBack = false;
    public:
        Player();
        void render(Renderer* renderer) override;
        void update(float dt, Input &input) override;

        RigidBody* getRigidBody() override;
};
