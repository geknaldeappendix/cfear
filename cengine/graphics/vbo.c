#include "vbo.h"

struct VBO vbo_create(int type, int dynamic) {
    struct VBO vbo = {
        .type = type,
        .dynamic = dynamic
    };
    glGenBuffers(1, &vbo.buffers);
    return vbo;
}

void vbo_destroy(struct VBO vbo) {
    glDeleteBuffers(1, &vbo.buffers);
}

void vbo_bind(struct VBO vbo) {
    glBindBuffer(vbo.type, vbo.buffers);
}

void vbo_buffer(struct VBO vbo, void *data, unsigned long offset, unsigned long count) {
    vbo_bind(vbo);
    glBufferData(vbo.type, count - offset, data, vbo.dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}
