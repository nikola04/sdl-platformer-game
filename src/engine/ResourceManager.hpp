#pragma once

#include <SDL2/SDL_image.h>
#include <string>
#include <unordered_map>

class ResourceManager {
    public:
        static ResourceManager& get() {
            static ResourceManager instance;
            return instance;
        }

        void init(SDL_Renderer* renderer);
        SDL_Texture* load(const std::string& path);
        void clear();

    private:
        SDL_Renderer* renderer;
        std::string basePath;
        std::pmr::unordered_map<std::string, SDL_Texture*> cache;
};
