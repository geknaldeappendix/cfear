#ifndef __REPOS_CFEAR_CENGINE_GRAPHICS_SHADER_H_
#define __REPOS_CFEAR_CENGINE_GRAPHICS_SHADER_H_

#include <stdio.h>
#include <stdlib.h>
#include "glad/gl.h"
#include "clib/logger.h"

struct Shader {
    int linked;
    unsigned int program;
};

struct Shader shader_create(char* vertex_shader_path, char* fragment_shader_path);
void shader_bind(struct Shader shader);
void shader_destroy(struct Shader shader);

#endif // __REPOS_CFEAR_CENGINE_GRAPHICS_SHADER_H_