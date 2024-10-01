#include <stdint.h>
#include "level.h"
#include "physics.h"
#include "renderer.h"

Collider LevelCollidersList[MAX_COLLIDERS];
Color level_background_color;

void render_level_background()
{
    // using current values of level_background_color
    SDL_SetRenderDrawColor(renderer, 
                                                        level_background_color.RGBA[Red], 
                                                        level_background_color.RGBA[Green], 
                                                        level_background_color.RGBA[Blue], 
                                                        level_background_color.RGBA[Alfa]);
    // clear renderings, fill  window with previous color
    SDL_RenderClear(renderer);
}

static void load_level_background_color(uint8_t level)
{
    switch (level)
    {
    case 0:
        level_background_color.RGBA[Red] = 55;
        level_background_color.RGBA[Green] = 180;
        level_background_color.RGBA[Blue] = 255;
        level_background_color.RGBA[Alfa] = 255;
        break;
    
    default:
        printf("Error loading level colliders: Level not found.");
        break;
    }
}

static void load_level_colliders(uint8_t level)
{
    switch (level)
    {
    case 0:
        for (int i = 0; i < MAX_COLLIDERS; i++)
        {
            // testing
            LevelCollidersList[i] = Empty_Collider;
        }
        break;

    default:
        printf("Error loading level colliders: Level not found.");
        break;
    }
}

void load_level(uint8_t level)
{
    load_level_background_color(level);
    load_level_colliders(level);
}