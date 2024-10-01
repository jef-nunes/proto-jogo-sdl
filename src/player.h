#ifndef PLAYER_H
#define PLAYER_H
#include <stdint.h>
#include <stdbool.h>
#include "physics.h"

enum EnumPlayerSprites{
    PLAYER_IDLE_1_SPRITE,
    PLAYER_IDLE_2_SPRITE,
    PLAYER_IDLE_3_SPRITE,
    PLAYER_IDLE_4_SPRITE,
    PLAYER_MOVE_1_SPRITE,
    PLAYER_MOVE_2_SPRITE,
    PLAYER_MOVE_3_SPRITE,
    PLAYER_MOVE_4_SPRITE,
    PLAYER_MOVE_5_SPRITE,
    PLAYER_JUMP_1_SPRITE,
    PLAYER_JUMP_2_SPRITE,
    PLAYER_SPRITE_COUNT
};


typedef struct
{
    // placeholder color for player sprite
    uint8_t color[4];

    // list for player sprite images paths
    char sprite_image_paths[PLAYER_SPRITE_COUNT][255];
    
    // index of current animation sprite
    uint8_t current_sprite_index;

    // player dimensions
    uint16_t width;
    uint16_t height;
    
    // player position
    int16_t pos_x;
    int16_t pos_y;
    
    // player collider object
    Collider collider;

    // player controllers
    Timer jump_cooldown;
    Timer jump_frame;
    uint8_t jump_force;
    uint8_t move_speed;
    bool is_alive;
    bool is_jumping;
    bool is_grounded;
}
Player;

extern Player player;
void load_player();
void render_player();
void handle_player_input(const SDL_Event *event);
#endif