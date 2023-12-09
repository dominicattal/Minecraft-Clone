#ifndef CHUNK_H
#define CHUNK_H

#include "../util/util.h"

#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16
#define CHUNK_SIZE_Z 16

#define CHUNK_VOLUME (CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z)

struct Chunk
{
    float* vertices;
    int vertices_size; // in bytes
    vec3i position;
    int* data;
    int count;
};

typedef struct Chunk Chunk;

void chunk_init(Chunk* chunk, int x, int y, int z);
int chunk_index(int x, int y, int z);
vec3i chunk_block_position(int idx);
void chunk_vertices(Chunk* chunk);

#endif