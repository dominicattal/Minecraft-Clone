#ifndef BLOCK_H
#define BLOCK_H

#include "../util/util.h"

#define BLOCK_ATLAS_WIDTH 16

enum Side {BACK=0, FRONT, RIGHT, LEFT, TOP, BOTTOM};
#define SIDE_FIRST BACK
#define SIDE_LAST BOTTOM

typedef enum Side Side;

enum BlockId
{
    AIR = 0,
    GRASS,
    STONE
};

typedef enum BlockId BlockId;
#define BLOCK_FIRST_ID AIR
#define BLOCK_LAST_ID STONE

struct Block 
{
    vec2i tex_coords[6];
};

typedef struct Block Block;

extern Block BLOCKS[BLOCK_LAST_ID + 1];

#define _BLOCK_DECL(_name)\
    extern void _name##_init();\
    _name##_init();

inline static void block_init()
{
    _BLOCK_DECL(grass);
    _BLOCK_DECL(stone);
}

#endif