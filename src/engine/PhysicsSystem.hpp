#pragma once

#include "GameObject.hpp"
#include "RigidBody.hpp"
#include <memory>
#include <vector>

class PhysicsSystem {
    public:
        PhysicsSystem(int width, int height);
        void update(float dt, std::vector<std::unique_ptr<GameObject>>& objects);

    private:
        int width, height;
        float gravity = 980.0f;

        bool overlaps(GameObject* a, GameObject* b);
        void resolveX(GameObject* obj, RigidBody* rb, std::vector<std::unique_ptr<GameObject>>& objects);
        void resolveY(GameObject* obj, RigidBody* rb, std::vector<std::unique_ptr<GameObject>>& objects);
        void checkWindowBoundaries(GameObject* obj, RigidBody* rb);
};
