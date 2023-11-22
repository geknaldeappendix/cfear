#include "mesh.h"

struct Mesh mesh_create() {
    struct Mesh mesh;

    mesh.vao = vao_create();
    mesh.vbo = vbo_create(GL_ARRAY_BUFFER, 0);
    mesh.ebo = vbo_create(GL_ELEMENT_ARRAY_BUFFER, 0);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    vbo_buffer(mesh.vbo, vertices, 0, sizeof(vertices));
    vao_attr(mesh.vao, mesh.vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), 0);
}

void mesh_destroy(struct Mesh mesh) {
    vao_destroy(mesh.vao);
    vbo_destroy(mesh.vbo);
    vbo_destroy(mesh.ebo)
}

void mesh_render(struct Mesh mesh, struct Shader shader) {
    shader_bind(shader);
    vao_bind(mesh.vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}