#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdint.h>
#include <stdbool.h>

// Time counting
typedef struct 
{
    uint16_t target;
    uint16_t counter;
}
Timer;

// Collision object
typedef struct
{
    uint16_t height;
    uint16_t width;
    int16_t pos_x;
    int16_t pos_y;
    bool is_active;
    bool is_trigger;
}
Collider;


// A empty collider with no dimensions
extern const Collider Empty_Collider;
#endif
