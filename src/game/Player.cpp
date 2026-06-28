#include "Player.hpp"
#include <cstdio>

Player::Player(): rb(), doubleJumped(false) {
    x = 100;
    y = 200;
    w = 50;
    h = 50;
}

RigidBody* Player::getRigidBody() {
    return &rb;
}

void Player::render(Renderer* renderer) {
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer->get(), 255, 0, 0, 255);

    SDL_RenderFillRect(renderer->get(), &rect);
}

void Player::update(float dt, Input &input) {
    rb.vx = 0;

    if (input.isHeld(SDLK_a))
        rb.vx = -200;
    if (input.isHeld(SDLK_d))
        rb.vx = 200;

    if (input.isPressed(SDLK_SPACE)){
        if (rb.onGround) {
            rb.vy = -600;
        } else if(!doubleJumped) {
            rb.vy = -400;
            doubleJumped = true;
        }
    }
    if (rb.onGround) doubleJumped = false;
}
