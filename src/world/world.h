#ifndef WORLD_H
#define WORLD_H

#include "chunk.h"
#include "noise.h"
#include "../util/util.h"
#include "../gfx/shader.h"

#define WORLD_SIZE_X 10
#define WORLD_SIZE_Y 1
#define WORLD_SIZE_Z 10
#define WORLD_VOLUME (WORLD_SIZE_X * WORLD_SIZE_Y * WORLD_SIZE_Z)

struct World 
{
    Camera camera;
    Chunk* chunks;
    u16 render_distance;
    vec3i chunk_offset;
};

typedef struct World World;

void world_init(Shader shader, vec2i viewport_size);
void world_render();
void world_reload();
s32 world_chunk_index(vec3i chunk_pos);
bool world_block_at(vec3i chunk_pos, vec3i block_pos);
void world_camera_move(vec3f moving, f32 dt);
void world_camera_turn(vec2f offset);

#endif