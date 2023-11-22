#include "renderer.h"

//TODO: TEMP BELOW
struct VBO vbo;
struct VAO vao;

int renderer_init(struct Renderer* renderer) {
    *renderer = (struct Renderer) {0};

    renderer->shaders[SHADER_DEFAULT] = shader_create("assets/shaders/default.vert", "assets/shaders/default.frag");
    
    //TODO: TEMP BELOW
    vao = vao_create();
    vbo = vbo_create(GL_ARRAY_BUFFER, 0);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    vbo_buffer(vbo, vertices, 0, sizeof(vertices));
    vao_attr(vao, vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), 0);

    return 0;
}

void renderer_destroy(struct Renderer* renderer) {
    for (int i = 0; i < SHADER_LAST; i++) {
        shader_destroy(renderer->shaders[i]);
    }

    //TODO: TEMP BELOW
    vao_destroy(vao);
    vbo_destroy(vbo);
}

void renderer_render(struct Renderer* renderer) {
    glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //TODO: TEMP BELOW
    shader_bind(renderer->shaders[SHADER_DEFAULT]);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
