#ifndef __REPOS_CFEAR_CENGINE_GRAPHICS_MESH_H_
#define __REPOS_CFEAR_CENGINE_GRAPHICS_MESH_H_

#include "shader.h"
#include "vbo.h"
#include "vao.h"

struct Mesh {
    struct VBO vbo, ebo;
    struct VAO vao;
};

struct Mesh mesh_create();

#endif // __REPOS_CFEAR_CENGINE_GRAPHICS_MESH_H_