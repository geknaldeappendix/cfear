#ifndef __REPOS_CFEAR_CENGINE_GRAPHICS_VBO_H_
#define __REPOS_CFEAR_CENGINE_GRAPHICS_VBO_H_

#include "glad/gl.h"

struct VBO {
    unsigned int buffers;
    int type;
    int dynamic;
};

struct VBO vbo_create(int type, int dynamic);
void vbo_destroy(struct VBO vbo);
void vbo_bind(struct VBO vbo);
void vbo_buffer(struct VBO vbo, void *data, unsigned long offset, unsigned long count);

#endif // __REPOS_CFEAR_CENGINE_GRAPHICS_VBO_H_
