#include "renderer.h"

int renderer_init(struct Renderer* renderer) {
    *renderer = (struct Renderer) {0};

    renderer->shaders[SHADER_DEFAULT] = shader_create("assets/shaders/default.vert", "assets/shaders/default.frag");
    
    return renderer->shaders[SHADER_DEFAULT].linked; 
}

void renderer_destroy(struct Renderer* renderer) {
    for (int i = 0; i < SHADER_LAST; i++) {
        shader_destroy(renderer->shaders[i]);
    }
}

void renderer_render(struct Renderer* renderer) {
    glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
