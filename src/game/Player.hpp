#pragma once

#include "../engine/GameObject.hpp"

class Player : public GameObject {
    private:
        RigidBody rb;
        bool doubleJumped;
    public:
        Player();
        void render(Renderer* renderer) override;
        void update(float dt, Input &input) override;

        RigidBody* getRigidBody() override;
};
