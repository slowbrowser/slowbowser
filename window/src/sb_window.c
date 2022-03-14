#include "sb_window.h"

#include <SDL.h>

struct sb_window
sb_window_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        abort();
    }

    SDL_Rect display_rect;
    if(SDL_GetDisplayBounds(0, &display_rect) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't get display bounds: %s", SDL_GetError());
        abort();
    }

    SDL_Window* window;
    SDL_Renderer* renderer;

    if (SDL_CreateWindowAndRenderer(display_rect.w, display_rect.h, SDL_WINDOW_RESIZABLE, &window, &renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        abort();
    }

    struct sb_window w;
    return w;
}

enum sb_event
sb_window_poll_event(struct sb_window w)
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT)
    {
        return sb_event_quit;
    }

    return sb_event_none;
}