#ifndef BLOCK_H
#define BLOCK_H

#include "../util/util.h"

struct Block
{
    vec3i position;
};

typedef struct Block Block;

void block_init(Block* block, int x, int y, int z);
char* block_hash(const Block block);

#endif