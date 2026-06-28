#pragma once

#include "../engine/GameObject.hpp"

class Platform : public GameObject {
    public:
        Platform();
        void render(Renderer* renderer) override;
};
