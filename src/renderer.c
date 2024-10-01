#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "renderer.h"

SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL; 

bool create_window()
{
    int16_t initialPosX = 0;
    int16_t initialPosY = 0;
    int16_t width = 640;
    int16_t height = 480;
    window = SDL_CreateWindow("Game Window", initialPosX, initialPosY, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return (renderer != NULL);
}

SDL_Texture* load_texture(const char* path)
{
    // printf("Loading texture from: %s\n", path);
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL) {
    //    printf("Failed to load texture: %s\n", IMG_GetError());
    }
    return texture;
}