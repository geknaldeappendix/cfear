#include "window.h"

struct Window window;

void window_resize(int width, int height) {
    glViewport(0, 0, width, height); 
}

int window_create(FunctionInit init, Function destroy, Function tick, Function render) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LOG_ERROR("SDL could not initialize, SDL_Error: %s", SDL_GetError());
        return 1;
    }

    window.sdl_window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
     SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    if (window.sdl_window == NULL) {
        LOG_ERROR("SDL window could not be created, SDL_Error: %s", SDL_GetError());
        return 1;
    }

    window.sdl_gl_context = SDL_GL_CreateContext(window.sdl_window);

    if (window.sdl_gl_context == NULL) {
        LOG_ERROR("SDL GL context could not be created, SDL_Error: %s", SDL_GetError());
        return 1;
    } else {
        SDL_GL_MakeCurrent(window.sdl_window, window.sdl_gl_context);
    }

    if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
        LOG_ERROR("GLAD could not initialize");
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //TODO: research why
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    int width, height;
    SDL_GetWindowSize(window.sdl_window, &width, &height);
    window_resize(width, height);

    SDL_Event event;
    int quit = 0;

    LOG_INFO("Successfully started window name=%s, width=%d, height=%d", SDL_GetWindowTitle(window.sdl_window), width, height);
    if (!init()) {
        LOG_ERROR("Error calling passed window init function please check logs");
        return 1;
    }

    while(!quit) {
        if (SDL_PollEvent(&event) > 0) {
            switch(event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                    window_resize(event.window.data1, event.window.data2);
                    break;
            }
        }

        tick();
        render();

        SDL_GL_SwapWindow(window.sdl_window);
    }

    destroy();

    SDL_GL_DeleteContext(window.sdl_gl_context);
    SDL_DestroyWindow(window.sdl_window);
    SDL_Quit();

    return 0;
}