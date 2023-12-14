#ifndef WORLD_H
#define WORLD_H

#include "chunk.h"
#include "../util/util.h"

#define HEIGHT 1

struct World 
{
    Chunk* chunks;
    u16 render_distance;
    vec3i chunk_offset;
};

typedef struct World World;

void world_init();
void world_render();
void world_reload();
s32 world_chunk_index(vec3i chunk_pos);
bool world_block_at(vec3i chunk_pos, vec3i block_pos);

#endif