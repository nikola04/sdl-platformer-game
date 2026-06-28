#include "Player.hpp"
#include "../engine/ResourceManager.hpp"
#include <SDL_render.h>
#include <cstdio>

Player::Player(): GameObject(150, 500, 57, 84), rb(), doubleJumped(false) {
    for (int i = 0; i < 20; i++) {
        char path[256];
        snprintf(path, sizeof(path), ASSETS_PATH "2/2_enemies_1_walk_%03d.png", i);
        walkFrames.push_back(ResourceManager::get().load(path));
    }
}

RigidBody* Player::getRigidBody() {
    return &rb;
}

void Player::render(Renderer* renderer) {
    SDL_Rect src = { 50, 30, 190, 280 };
    SDL_Rect dest = { (int)x, (int)y, (int)w, (int)h };

    SDL_RendererFlip flip = facingBack ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer->get(), walkFrames[currentFrame], &src, &dest, 0, NULL, flip);
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
    if (frameTimer >= 0.016f) {
        frameTimer = 0;
        if (rb.vx != 0)
            currentFrame = (currentFrame + 1) % walkFrames.size();
    }
}
