#include "Engine.hpp"
#include "GameObject.hpp"
#include "PhysicsSystem.hpp"
#include "Renderer.hpp"
#include <SDL.h>
#include <chrono>
#include <cstdio>
#include <memory>
#include "Config.hpp"
#include "ResourceManager.hpp"

Engine::Engine(): physicsSystem(WINDOW_WIDTH, WINDOW_HEIGHT),
    input(),
    objects(),
    running(true),
    window("Game", WINDOW_WIDTH, WINDOW_HEIGHT),
    renderer(window.get(), WINDOW_WIDTH, WINDOW_HEIGHT) {
    ResourceManager::get().init(renderer.get());
};

void Engine::addObject(std::unique_ptr<GameObject> object) {
    objects.push_back(std::move(object));
}

void Engine::run() {
    printf("Starting engine...\n");
    renderer.printRendererInfo();

    auto last = std::chrono::high_resolution_clock::now();

    while (running) {
        input.begindFrame();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }

            input.handleEvent(event);
        }

        auto now = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(now - last).count();
        last = now;

        update(dt, input);
        physicsSystem.update(dt, objects);

        render();
    }
}

void Engine::update(float dt, Input &input) {
    for(auto& obj : objects) {
        obj->update(dt, input);
    }
}

void Engine::render() {
    renderer.clear();

    for(int i = 0; i < objects.size(); i++) {
        objects[i]->render(&renderer);
    }

    renderer.present();
}
