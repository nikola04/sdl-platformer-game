#pragma once

#include "../engine/GameObject.hpp"
#include <SDL_render.h>

class Player : public GameObject {
    private:
        RigidBody rb;
        bool doubleJumped;
        SDL_Texture* walkSprite;
        float frameTimer = 0.0;
        int currentFrame = 0;
        int firstWalkFrame = 18;
        int walkFrames = 6;
        int firstJumpFrame = 6;
        int jumpFrames = 1;
        bool facingBack = false;
    public:
        Player();
        void render(Renderer* renderer) override;
        void update(float dt, Input &input) override;

        RigidBody* getRigidBody() override;
};
