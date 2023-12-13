#ifndef CHUNK_H
#define CHUNK_H

#include "../gfx/vao.h"
#include "../gfx/vbo.h"
#include "../util/util.h"

#define CHUNK_SIZE_X 32
#define CHUNK_SIZE_Y 32
#define CHUNK_SIZE_Z 32

#define CHUNK_VOLUME (CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z)

enum Side {BACK=0, FRONT, RIGHT, LEFT, TOP, BOTTOM};
#define FIRST_SIDE BACK
#define LAST_SIDE BOTTOM

typedef enum Side Side;

struct Chunk
{
    float* vertices;
    unsigned int* indices;
    int count, vertices_size, indices_size; 
    vec3i position;
    int* data;
    VAO vao;
    VBO vbo, ebo;
};

typedef struct Chunk Chunk;

void chunk_init(Chunk* chunk, int x, int y, int z);
int chunk_index(int x, int y, int z);
vec3i chunk_block_position(int idx);
void chunk_generate_data(Chunk* chunk);
void chunk_vertices(Chunk* chunk);
void chunk_render(Chunk chunk);

#endif