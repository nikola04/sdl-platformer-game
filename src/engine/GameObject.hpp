#pragma once
#include "Renderer.hpp"

class GameObject {
    public:
        virtual ~GameObject() = default;

        virtual void render(Renderer* renderer) = 0;
        virtual void update(float dt){};
};
