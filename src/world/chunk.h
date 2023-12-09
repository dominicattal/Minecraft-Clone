#ifndef CHUNK_H
#define CHUNK_H

#include "../util/util.h"

#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16
#define CHUNK_SIZE_Z 16

#define CHUNK_VOLUME (CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z)

enum Side {BACK=0, FRONT, RIGHT, LEFT, TOP, BOTTOM};
#define FIRST_SIDE BACK
#define LAST_SIDE BOTTOM

typedef enum Side Side;

struct Chunk
{
    float* vertices;
    unsigned int* indices;
    int vertices_size; 
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