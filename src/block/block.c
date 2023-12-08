#include "block.h"

void block_init(Block* block, int x, int y, int z)
{
    vec3i_init(&block->position, x, y, z);
}

char* block_hash(const Block block)
{
    return vec3i_hash(block.position);
}