#pragma once

struct RigidBody {
    float vx = 0, vy = 0;
    float mass = 1.0f;
    bool onGround = false;
};
