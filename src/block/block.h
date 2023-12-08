#ifndef BLOCK_H
#define BLOCK_H

#include "../util/util.h"

struct Block
{
    vec3f position;
};

typedef struct Block Block;

void block_init(Block* block, float x, float y, float z);

#endif