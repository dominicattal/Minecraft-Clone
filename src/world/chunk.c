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

static int dirs[] = {
    0, 0, -1,  // -z
    0, 0, 1,  // +z
    1, 0, 0,  // +x
    -1, 0, 0, // -x
    0, 1, 0,  // +y
    0, -1, 0  // -y
};

static void fill_vertices(Chunk* chunk, vec3i pos)
{
    int x = pos.x, y = pos.y, z = pos.z;
    int offset = chunk->vertices_size / sizeof(float);
    int num_sides = 0;
    for (Side side = FIRST_SIDE; side <= LAST_SIDE; side++)
    {
        int idx = chunk_index(x + dirs[3*side], y + dirs[3*side+1], z + dirs[3*side+2]);
        if (idx != -1 && chunk->data[idx] == 1)
            continue;
        for (int i = 0; i < 6; i++)
        {
            unsigned int index = s_indices[side*6 + i];
            chunk->vertices[3 * (num_sides * 6 + i) + offset]     = s_vertices[3 * index]     + x + CHUNK_SIZE_X * chunk->position.x;
            chunk->vertices[3 * (num_sides * 6 + i) + offset + 1] = s_vertices[3 * index + 1] + y + CHUNK_SIZE_Y * chunk->position.y;
            chunk->vertices[3 * (num_sides * 6 + i) + offset + 2] = s_vertices[3 * index + 2] + z + CHUNK_SIZE_Z * chunk->position.z;
        }
        num_sides += 1;
    }
    int size = num_sides * 18 * sizeof(float);
    chunk->vertices_size += size;
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
        for (int y = 0; y < CHUNK_SIZE_Y; y++)
        {
            for (int z = 0; z < CHUNK_SIZE_Z; z++)
            {
                chunk->data[chunk_index(x, y, z)] = 1;
                chunk->count++;
            }
        }
    }
    chunk_vertices(chunk);
}

int chunk_index(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0) 
        return -1;
    if (x >= CHUNK_SIZE_X || y >= CHUNK_SIZE_Y || z >= CHUNK_SIZE_Z) 
        return -1;
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
    free(chunk->vertices);
    free(chunk->indices);
    chunk->vertices_size = 0;
    chunk->vertices = malloc(CHUNK_VOLUME * 6 * 6 * 3 * sizeof(float));
    assert(chunk->vertices != NULL);
    chunk->indices  = malloc(0);
    for (int i = 0; i < CHUNK_VOLUME; i++)
    {
        if (chunk->data[i] == 1)
            fill_vertices(chunk, chunk_block_position(i));
    }
    if (chunk->vertices_size > 0)
    {
        chunk->vertices = realloc(chunk->vertices, chunk->vertices_size);
        assert(chunk->vertices != NULL);
    }
    else
    {
        free(chunk->vertices);
    }
}

