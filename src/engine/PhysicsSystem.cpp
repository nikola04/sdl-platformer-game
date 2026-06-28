#include "PhysicsSystem.hpp"
#include "GameObject.hpp"
#include "RigidBody.hpp"

PhysicsSystem::PhysicsSystem(int width, int height): width(width), height(height) {}

bool PhysicsSystem::overlaps(GameObject* a, GameObject* b) {
    return (a->x < b->x + b->w) && (a->x + a->w > b->x) && (a->y < b->y + b->h) && (a->y + a->h > b->y);
};

void PhysicsSystem::resolveX(GameObject* obj, RigidBody* rb, std::vector<std::unique_ptr<GameObject>>& objects) {
    for (auto& other : objects) {
        if (other.get() == obj) continue;
        if (!other->collidable) continue;
        if (other->getRigidBody()) continue; // skip dynamic objects
        if (!overlaps(obj, other.get())) continue;

        if (obj->x + obj->w > other->x && rb->vx > 0){
            obj->x = other->x - obj->w;
            rb->vx = 0;
        } else if (obj->x < other->x + other->w && rb->vx < 0){
            obj->x = other->x + other->w;
            rb->vx = 0;
        }

    }
};


void PhysicsSystem::resolveY(GameObject* obj, RigidBody* rb, std::vector<std::unique_ptr<GameObject>>& objects) {
    for (auto& other : objects) {
        if (other.get() == obj) continue;
        if (!other->collidable) continue;
        if (other->getRigidBody()) continue; // skip dynamic objects
        if (!overlaps(obj, other.get())) continue;

        if (obj->y + obj->h > other->y && rb->vy > 0) {
            obj->y = other->y - obj->h;
            rb->vy = 0;
            rb->onGround = true;
        } else if (obj->y < other->y + other->h && rb->vy <= 0) {
            obj->y = other->y + other->h;
            rb->vy = 0;
        }
    }
};

void PhysicsSystem::checkWindowBoundaries(GameObject* obj, RigidBody* rb) {
    if (obj->x < 0) { obj->x = 0; rb->vx = 0; }
    if (obj->x + obj->w > width) { obj->x = width - obj->w; rb->vx = 0; }
    if (obj->y < 0) { obj->y = 0; rb->vy = 0; }
    if(obj->y + obj->h > height) {
        obj->y = height - obj->h;
        rb->onGround = true;
        rb->vy = 0;
    }
}

void PhysicsSystem::update(float dt, std::vector<std::unique_ptr<GameObject>>& objects) {
    for(auto& obj : objects) {
        RigidBody* rb = obj->getRigidBody();
        if (!rb) continue;

        rb->onGround = false;
        rb->vy += gravity * dt;

        obj->x += rb->vx * dt;
        resolveX(obj.get(), rb, objects);

        obj->y += rb->vy * dt;
        resolveY(obj.get(), rb, objects);

        checkWindowBoundaries(obj.get(), rb);
    }
};
