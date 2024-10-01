#ifndef RENDERER_H
#define RENDERER_H
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
extern SDL_Renderer *renderer;
extern SDL_Window *window;
SDL_Texture *load_texture(const char* path);
bool create_window();
enum EnumRGBA
{
    Red,
    Green,
    Blue,
    Alfa
};
typedef struct 
{
    uint8_t RGBA[4];
}
Color;
#endif