#include "renderer.hpp"

#include "exception.hpp"

Renderer::Renderer(size_t width, size_t height) : screen_width(width), screen_height(height) {
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw SDL_Init_Fail;
    }

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);

    if (!window) {
        throw SDL_Window_Fail;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        throw SDL_Renderer_Fail;
    }

}

Renderer::~Renderer() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::Render() {
    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
    SDL_RenderPresent(renderer);
}