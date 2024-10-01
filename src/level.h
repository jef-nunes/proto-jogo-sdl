#ifndef LEVEL_H
#define LEVEL_H
#include "physics.h"
#include "renderer.h"
#define MAX_COLLIDERS 100
extern Collider LevelCollidersList[MAX_COLLIDERS];
extern Color level_background_color;
static void load_level_colliders(uint8_t level);
static void load_level_background_color(uint8_t level);
void render_level_background();
void load_level(uint8_t level);
#endif