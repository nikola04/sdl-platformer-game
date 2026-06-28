#pragma once
#include "Renderer.hpp"
#include "Input.hpp"
#include "RigidBody.hpp"

class GameObject {
    public:
        float x = 0, y = 0, w = 0, h = 0;

        virtual ~GameObject() = default;

        virtual void render(Renderer* renderer) = 0;
        virtual void update(float dt, Input &input) {};

        virtual RigidBody* getRigidBody() {
            return nullptr;
        }
};
