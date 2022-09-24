#include "main.hpp"

#include "controller.hpp"
#include "renderer.hpp"
#include "game.hpp"
#include "exception.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    try {
        Renderer renderer(width, height);
        Controller controller;
        Game(width, height).Run((target_frame_duration), renderer, controller);
    } catch (Exception e)  {
        switch (e.GetType()) {
            case SDL_Init_Fail: std::cout << ("Unable to initialise SDL\n"); break;
            case SDL_Window_Fail: std::cout << ("Unable to create SDL Window\n"); break;
            case SDL_Renderer_Fail: std::cout << ("Unable to create SDL Renderer\n"); break;
        }
    }
    return 0;
}