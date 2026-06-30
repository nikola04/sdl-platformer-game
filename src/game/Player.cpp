#include "Player.hpp"
#include "../engine/ResourceManager.hpp"
#include <SDL_render.h>
#include <cstdio>

Player::Player(): GameObject(150, 500, 64, 56), rb(), doubleJumped(false) {
    walkSprite = ResourceManager::get().load(ASSETS_PATH "player/DinoSprites - mort.png");
}

RigidBody* Player::getRigidBody() {
    return &rb;
}

void Player::render(Renderer* renderer) {
    int spriteX = currentFrame * 24;
    SDL_Rect src = { spriteX, 0, 24, 20 };
    SDL_Rect dest = { (int)x, (int)y, (int)w, (int)h };

    SDL_RendererFlip flip = facingBack ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer->get(), walkSprite, &src, &dest, 0, NULL, flip);
}

void Player::update(float dt, Input &input) {
    rb.vx = 0;

    if (rb.onGround) doubleJumped = false;

    if (input.isHeld(SDLK_a)) {
        rb.vx = -200;
        facingBack = true;
    }
    if (input.isHeld(SDLK_d)) {
        rb.vx = 200;
        facingBack = false;
    }

    if (input.isPressed(SDLK_SPACE)){
        if (rb.onGround) {
            rb.vy = -600;
        } else if(!doubleJumped) {
            rb.vy = -400;
            doubleJumped = true;
        }
    }

    frameTimer += dt;
    if (frameTimer >= 0.036f) {
        frameTimer = 0;
        if (!rb.onGround) currentFrame = (currentFrame + 1) % jumpFrames + firstJumpFrame;
        else if(rb.vx != 0) currentFrame = (currentFrame + 1) % walkFrames + firstWalkFrame;
        else currentFrame = 1;
    }
}
