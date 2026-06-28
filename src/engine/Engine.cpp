#include "Engine.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"
#include <SDL.h>
#include <chrono>
#include <memory>

Engine::Engine(): objects(), running(true), window("Game", 800, 600), renderer(window.get()) {

};

void Engine::addObject(std::unique_ptr<GameObject> object) {
    objects.push_back(std::move(object));
}

void Engine::run() {
    auto last = std::chrono::high_resolution_clock::now();

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        auto now = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(now - last).count();
        last = now;

        update(dt);

        render();
    }
}


void Engine::update(float dt) {
    for(auto& obj : objects) {
        obj->update(dt);
    }
}


void Engine::render() {
    renderer.clear();

    for(int i = 0; i < objects.size(); i++){
        objects[i]->render(&renderer);
    }

    renderer.present();
}
