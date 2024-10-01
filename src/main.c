#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include "player.h"
#include "renderer.h"
#include "level.h"

volatile sig_atomic_t running = 1;

void handle_sigint(int sig)
{
    printf("quiting...");
    running = 0;
}

void update(const SDL_Event *event)
{
    // Handle player input
    handle_player_input(event);

    // Clear renderer
    // 1. set drawing color: black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // 2. clear renderings, fill  window with previous color
    SDL_RenderClear(renderer);
    
    // Rendering logic for level background
    render_level_background();

    // Rendering logic for player character
    render_player();

    // Update the screen with any rendering performed since the previous call.
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}



void start_new_game()
{
    printf("Loading...");
    load_player();
    load_level(0);
    printf("Finished loading.");
}

void game_loop()
{
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)){
            // quit
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        // next frame update
        update(&event);
        }
    }
}

int main(void) {
    // Set handler for SIGINT 
    signal(SIGINT, handle_sigint);

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || !create_window()) {
        printf("SDL Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // Init SDL Image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
    printf("SDL_image Error: %s\n", IMG_GetError());
    SDL_Quit();
    return 1;
    }

    // Start new game
    start_new_game();
    // Start game loop
    game_loop();

    // Terminate SDL
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
