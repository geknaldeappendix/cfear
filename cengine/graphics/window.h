#ifndef __CFEAR_CENGINE_GRAPHICS_WINDOW_H_
#define __CFEAR_CENGINE_GRAPHICS_WINDOW_H_

#include "SDL2/SDL.h"
#include "glad/gl.h"
#include "clib/logger.h"

typedef void (*Function)();

struct Window {
    SDL_Window* sdl_window;
    SDL_GLContext sdl_gl_context;
};

int window_create(Function init, Function destroy, Function tick, Function render);

extern struct Window window;

#endif // __CFEAR_CENGINE_GRAPHICS_WINDOW_H_ 