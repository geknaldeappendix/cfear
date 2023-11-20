#include "window.h"
#include "SDL_render.h"

int window_create() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LOG_ERROR("SDL could not initialize, SDL_Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("title", 800, 600, 0);

    if (window == NULL) {
        LOG_ERROR("SDL window could not be created, SDL_Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);   

    if (renderer == NULL) {
        LOG_ERROR("SDL renderer could not be created, SDL_Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Event event;
    int quit = 0;

    while(!quit) {
        if (SDL_PollEvent(&event) > 0) {
            switch(event.type) {
                case SDL_EVENT_QUIT:
                    quit = 1;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}