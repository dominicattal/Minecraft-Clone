#ifndef BLOCK_H
#define BLOCK_H

#include "../util/util.h"

enum Side {BACK=0, FRONT, RIGHT, LEFT, TOP, BOTTOM};
#define SIDE_FIRST BACK
#define SIDE_LAST BOTTOM

typedef enum Side Side;

enum BlockId
{
    AIR = 0,
    GRASS
};

typedef enum BlockID BlockID;
#define BLOCK_FIRST_ID AIR
#define BLOCK_LAST_ID GRASS

struct Block 
{
};

typedef struct Block Block;

extern Block Blocks[BLOCK_LAST_ID + 1];

#define _BLOCK_DECL(_name)\
    extern void _name##_init();

static inline void block_init()
{
    _BLOCK_DECL(air);
    _BLOCK_DECL(grass);
}

#endif