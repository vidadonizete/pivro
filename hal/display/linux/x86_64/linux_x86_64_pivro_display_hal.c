#include <stdio.h>

#include <SDL2/SDL.h>

#include <pivro/display.h>

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Event event;

void pivro_display_initialize(
    uint16_t width,
    uint16_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Error starting SDL2: %s", SDL_GetError());
        exit(0);
    }

    if (SDL_CreateWindowAndRenderer(
            width,
            height,
            SDL_WINDOW_SHOWN,
            &window,
            &renderer) < 0)
    {
        fprintf(stderr, "Error starting SDL2: %s", SDL_GetError());
        exit(0);
    }

    SDL_SetWindowTitle(window, "Pivro");

    //SDL_RenderSetScale(renderer, 10, 10);
    SDL_SetWindowSize(window, width, height);
}

void pivro_display_resize(
    uint16_t x1,
    uint16_t x2,
    uint16_t y1,
    uint16_t y2)
{
}

void pivro_display_draw_buffer(
    uint16_t *buffer,
    size_t size)
{
}

void pivro_display_tick()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return pivro_display_terminate();
        }
    }
}

void pivro_display_terminate()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    window = NULL;
    renderer = NULL;
}