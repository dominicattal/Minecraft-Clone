#include "block.h"

void block_init(Block* block, float x, float y, float z)
{
    vec3f_init(&block->position, x, y, z);
}