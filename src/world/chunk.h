#ifndef CHUNK_H
#define CHUNK_H

#include "../block/block.h"
#include "../gfx/vao.h"
#include "../gfx/vbo.h"
#include "../util/util.h"

#define CHUNK_SIZE_X 32
#define CHUNK_SIZE_Y 32
#define CHUNK_SIZE_Z 32

#define CHUNK_VOLUME (CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z)

struct Chunk
{
    f32* vertices;
    u32* indices;
    u32 data_count, face_count;
    vec3i position;
    u8* data;
    VAO vao;
    VBO vbo, ebo;
};

typedef struct Chunk Chunk;

void chunk_init(Chunk* chunk, s32 x, s32 y, s32 z);
s32 chunk_block_index(s32 x, s32 y, s32 z);
vec3i chunk_block_position(s32 idx);
void chunk_generate_data(Chunk* chunk);
void chunk_generate_vertices(Chunk* chunk);
void chunk_render(Chunk* chunk);
void chunk_reload(Chunk* chunk);

#endif