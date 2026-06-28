#pragma once

#include "Window.hpp"
#include "Renderer.hpp"
#include "GameObject.hpp"
#include <memory>
#include <vector>

class Engine {
    public:
        Engine();
        void addObject(std::unique_ptr<GameObject> object);
        void run();


    private:
        bool running;
        std::vector<std::unique_ptr<GameObject>> objects;

        Window window;
        Renderer renderer;

        void update(float dt);
        void render();
};
