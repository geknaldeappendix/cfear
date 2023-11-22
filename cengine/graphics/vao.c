#include "vao.h"

struct VAO vao_create() {
    struct VAO vao;
    glGenVertexArrays(1, &vao.arrays);
    return vao;
}

void vao_destroy(struct VAO vao) {
    glDeleteVertexArrays(1, &vao.arrays);
}

void vao_bind(struct VAO vao) {
    glBindVertexArray(vao.arrays);
}

void vao_attr(
    struct VAO vao,
    struct VBO vbo,
    unsigned int index,
    int size,
    unsigned int type,
    int stride,
    unsigned long offset
) {
    vao_bind(vao);
    vbo_bind(vbo);

    switch (type) {
        case GL_BYTE:
        case GL_UNSIGNED_BYTE:
        case GL_SHORT:
        case GL_UNSIGNED_SHORT:
        case GL_INT:
        case GL_UNSIGNED_INT:
        case GL_INT_2_10_10_10_REV:
        case GL_UNSIGNED_INT_2_10_10_10_REV:
            glVertexAttribIPointer(index, size, type, stride, (void*) offset);
            break;
        default:
            glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void*) offset);
            break;
    }
    
    glEnableVertexAttribArray(index);
}
