#include "Square.hpp"

Square::Square(): w(100), h(100), x(50), y(200) {};

void Square::render(Renderer* renderer) {
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;


    SDL_SetRenderDrawColor(
        renderer->get(),
        255,
        0,
        0,
        255
    );


    SDL_RenderFillRect(
        renderer->get(),
        &rect
    );
}

void Square::update(float dt, Input &input) {
    float fps = 1.0f / dt;
    if (input.isHeld(SDLK_LEFT))
        x -= 100 * dt;
    if (input.isHeld(SDLK_RIGHT))
        x += 100 * dt;
    if (input.isHeld(SDLK_UP))
        y -= 100 * dt;
    if (input.isHeld(SDLK_DOWN))
        y += 100 * dt;
    printf("Updating square in %f fps \n", fps);
}
