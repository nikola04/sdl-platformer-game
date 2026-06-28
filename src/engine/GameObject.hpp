#pragma once
#include "Renderer.hpp"
#include "Input.hpp"
#include "RigidBody.hpp"

class GameObject {
    public:
        float x = 0, y = 0, w = 0, h = 0;
        bool collidable = true;
        GameObject(float x, float y, float w, float h): x(x), y(y), w(w), h(h) {}
        GameObject(float x, float y, float w, float h, bool collidable): x(x), y(y), w(w), h(h), collidable(collidable) {}


        virtual ~GameObject() = default;

        virtual void render(Renderer* renderer) = 0;
        virtual void update(float dt, Input &input) {};

        virtual RigidBody* getRigidBody() {
            return nullptr;
        }
};
