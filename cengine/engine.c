#include "engine.h"

struct Renderer renderer;

int init() {
    return renderer_init(&renderer);
}

void destroy() {
    renderer_destroy(&renderer);
}

void tick() {

}

void render() {
    renderer_render(&renderer);
}

int engine_create() {
    if (!window_create(init, destroy, tick, render)) {
        return 1;
    }

    return 0;
}
