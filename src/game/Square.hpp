#pragma once

#include "../engine/GameObject.hpp"

class Square : public GameObject {
    public:
        Square();
        void render(Renderer* renderer) override;
        void update(float dt) override;

    private:
        int x, y, w, h;
};
