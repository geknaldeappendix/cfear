#ifndef __REPOS_CFEAR_CENGINE_GRAPHICS_RENDERER_H_
#define __REPOS_CFEAR_CENGINE_GRAPHICS_RENDERER_H_

#include "glad/gl.h"
#include "shader.h"

#include "graphics/vbo.h" //TODO: temp
#include "graphics/vao.h"

enum Shaders {
    SHADER_DEFAULT = 0
};
#define SHADER_LAST SHADER_DEFAULT

struct Renderer {
    struct Shader shaders[SHADER_LAST + 1];
};

int renderer_init(struct Renderer* renderer);
void renderer_destroy(struct Renderer* renderer);
void renderer_render(struct Renderer* renderer);

#endif // __REPOS_CFEAR_CENGINE_GRAPHICS_RENDERER_H_