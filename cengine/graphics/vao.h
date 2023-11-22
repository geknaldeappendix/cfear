#ifndef __REPOS_CFEAR_CENGINE_GRAPHICS_VAO_H_
#define __REPOS_CFEAR_CENGINE_GRAPHICS_VAO_H_

#include "glad/gl.h"
#include "vbo.h"

struct VAO {
    unsigned int arrays;
};

struct VAO vao_create(void);
void vao_destroy(struct VAO vao);
void vao_bind(struct VAO vao);
void vao_attr(
    struct VAO vao,
    struct VBO vbo,
    unsigned int index,
    int size,
    GLenum type,
    int stride,
    unsigned long offset
);

#endif // __REPOS_CFEAR_CENGINE_GRAPHICS_VAO_H_
