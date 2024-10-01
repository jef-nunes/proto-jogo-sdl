#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"
#include "renderer.h"

Player player;

void load_player()
{
    player.color[Red] = 32;
    player.color[Green] = 186;
    player.color[Blue] = 255;
    player.color[Alfa] = 255;
    player.current_sprite_index = 0;
    strcpy(player.sprite_image_paths[PLAYER_IDLE_1_SPRITE], "./textures/player/player_idle_1.png");
    strcpy(player.sprite_image_paths[PLAYER_IDLE_2_SPRITE], "./textures/player/player_idle_2.png");
    strcpy(player.sprite_image_paths[PLAYER_IDLE_3_SPRITE], "./textures/player/player_idle_3.png");
    strcpy(player.sprite_image_paths[PLAYER_IDLE_4_SPRITE], "./textures/player/player_idle_4.png");
    strcpy(player.sprite_image_paths[PLAYER_MOVE_1_SPRITE], "./textures/player/player_move_1.png");
    strcpy(player.sprite_image_paths[PLAYER_MOVE_2_SPRITE], "./textures/player/player_move_2.png");
    strcpy(player.sprite_image_paths[PLAYER_MOVE_3_SPRITE], "./textures/player/player_move_3.png");
    strcpy(player.sprite_image_paths[PLAYER_MOVE_4_SPRITE], "./textures/player/player_move_4.png");
    strcpy(player.sprite_image_paths[PLAYER_MOVE_5_SPRITE], "./textures/player/player_move_5.png");
     strcpy(player.sprite_image_paths[PLAYER_JUMP_1_SPRITE], "./textures/player/player_jump_1.png");
      strcpy(player.sprite_image_paths[PLAYER_JUMP_2_SPRITE], "./textures/player/player_jump_2.png");
    player.width = 64;
    player.height = 64;
    player.pos_x = 0;
    player.pos_y = 0;
    player.collider.is_active = true;
    player.collider.width = player.width;
    player.collider.height = player.height;
    player.collider.pos_x = player.pos_x;
    player.collider.pos_y = player.pos_y;
    player.jump_cooldown.counter = 0;
    player.jump_cooldown.target = 0;
    player.jump_frame.counter = 0;
    player.jump_frame.target = 0;
    player.move_speed = 3;
    player.is_alive = true;
    player.is_grounded = true;
    player.is_jumping = false;
}

void render_player() {
    /*    // placeholder rectangle for player character
    SDL_Rect rect = {
                                            player.pos_x,
                                            player.pos_y, 
                                            player.width, 
                                            player.height
                                        };
    // select player color as drawing color
    SDL_SetRenderDrawColor(
                                                        renderer, 
                                                        player.color[Red],
                                                        player.color[Green],
                                                        player.color[Blue],
                                                        player.color[Alfa]
                                                        );
    //  rendering method
    SDL_RenderFillRect(renderer, &rect); */

    SDL_Texture *texture = load_texture(player.sprite_image_paths[player.current_sprite_index]);
    SDL_Rect dest_rect = { player.pos_x, player.pos_y, player.width, player.height };
    
    // Rendering player sprite
    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
    
    // Free memory
    SDL_DestroyTexture(texture);
}

void handle_player_input(const SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.sym) {
            case SDLK_w:
            case SDLK_SPACE:
                if (event->type == SDL_KEYDOWN) {
                  //  printf("Player: jump\n");
                }
                break;
            case SDLK_a:
                if (event->type == SDL_KEYDOWN) {
                   // printf("Player: move left\n");
                    player.pos_x -= player.move_speed;
                }
                break;
            case SDLK_d:
                if (event->type == SDL_KEYDOWN) {
                   // printf("Player: move right\n");
                    player.pos_x += player.move_speed;
                }
                break;
        }
    }
}

