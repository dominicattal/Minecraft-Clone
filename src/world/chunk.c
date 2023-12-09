#include "chunk.h"

static float s_vertices[] = {
    0, 0, 0,
    1, 0, 0,
    1, 1, 0,
    0, 1, 0,
    0, 0, 1,
    1, 0, 1,
    1, 1, 1,
    0, 1, 1
};
static unsigned int s_indices[] = {
    1, 0, 3, 1, 3, 2, // -z
    4, 5, 6, 4, 6, 7, // +z
    5, 1, 2, 5, 2, 6, // +x
    0, 4, 7, 0, 7, 3, // -x
    2, 3, 7, 2, 7, 6, // +y
    5, 4, 0, 5, 0, 1  // -y
};

static void fill_vertices(Chunk* chunk, int offset, int x, int y, int z)
{
    for (Side side = FIRST_SIDE; side <= LAST_SIDE; side++)
    {
        for (int i = 0; i < 6; i++)
        {
            unsigned int index = s_indices[side*6 + i];
            chunk->vertices[3 * (side * 6 + i) + offset]     = s_vertices[3 * index]     + x + CHUNK_SIZE_X * chunk->position.x;
            chunk->vertices[3 * (side * 6 + i) + offset + 1] = s_vertices[3 * index + 1] + y + CHUNK_SIZE_Y * chunk->position.y;
            chunk->vertices[3 * (side * 6 + i) + offset + 2] = s_vertices[3 * index + 2] + z + CHUNK_SIZE_Z * chunk->position.z;
        }
    }
}

void chunk_init(Chunk* chunk, int x, int y, int z)
{
    vec3i position;
    vec3i_init(&position, x, y, z);
    chunk->position = position;
    chunk->data = malloc(CHUNK_VOLUME * sizeof(int));
    chunk->vertices = malloc(0);
    chunk->indices = malloc(0);
    assert(chunk->data != NULL);
    chunk->count = 0;

    for (int x = 0; x < CHUNK_SIZE_X; x++)
    {
        for (int z = 0; z < CHUNK_SIZE_Z; z++)
        {
            chunk->data[chunk_index(x, 0, z)] = 1;
            chunk->count++;
        }
    }
    chunk_vertices(chunk);
}

int chunk_index(int x, int y, int z)
{
    return x + CHUNK_SIZE_X * y + CHUNK_SIZE_X * CHUNK_SIZE_Y * z;
}

vec3i chunk_block_position(int idx)
{
    vec3i pos;
    pos.z = idx / (CHUNK_SIZE_X * CHUNK_SIZE_Y);
    idx -= pos.z * CHUNK_SIZE_X * CHUNK_SIZE_Y;
    pos.y = idx / CHUNK_SIZE_X;
    idx -= pos.y * CHUNK_SIZE_X;
    pos.x = idx;
    return pos;
}

void chunk_vertices(Chunk* chunk)
{
    int num_vertices = 0;
    free(chunk->vertices);
    free(chunk->indices);
    chunk->vertices = malloc(0);
    chunk->indices = malloc(0);
    for (int i = 0; i < CHUNK_VOLUME; i++)
    {
        if (chunk->data[i] == 1)
        {
            vec3i pos = chunk_block_position(i);
            chunk->vertices = realloc(chunk->vertices, (num_vertices + 108) * sizeof(float));
            assert(chunk->vertices != NULL);
            fill_vertices(chunk, num_vertices, pos.x, pos.y, pos.z);
            num_vertices += 108;
        }
    }
    chunk->vertices_size = num_vertices * sizeof(float);
}

