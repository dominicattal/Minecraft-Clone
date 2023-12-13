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

static int dirs[] = {
    0, 0, -1,  // -z
    0, 0, 1,  // +z
    1, 0, 0,  // +x
    -1, 0, 0, // -x
    0, 1, 0,  // +y
    0, -1, 0  // -y
};

/*
static unsigned int s_indices[] = {
    1, 0, 3, 1, 3, 2, // -z
    4, 5, 6, 4, 6, 7, // +z
    5, 1, 2, 5, 2, 6, // +x
    0, 4, 7, 0, 7, 3, // -x
    2, 3, 7, 2, 7, 6, // +y
    5, 4, 0, 5, 0, 1  // -y
};
*/

static unsigned int side_idxs[] = {
    1, 0, 3, 2, //-z
    4, 5, 6, 7, //+z
    5, 1, 2, 6, //+x
    0, 4, 7, 3, //-x
    2, 3, 7, 6, //+y
    5, 4, 0, 1  //-y
};

static bool has_adjacent(const Chunk* chunk, const vec3i pos, const Side side)
{
    int idx = chunk_index(pos.x + dirs[3*side], pos.y + dirs[3*side+1], pos.z + dirs[3*side+2]);
    if (idx != -1 && chunk->data[idx] == 1)
        return true;
    return false;
}   

static void fill_vertices(Chunk* chunk, vec3i pos)
{
    int vertex_offset = chunk->vertices_size / sizeof(float);
    int index_offset = chunk->indices_size / sizeof(int);
    for (Side side = FIRST_SIDE; side <= LAST_SIDE; side++)
    {
        if (has_adjacent(chunk, pos, side))
            continue;
        
        for (int i = 0; i < 4; i++)
        {
            unsigned int index = side_idxs[4*side+i];
            chunk->vertices[3 * i + vertex_offset]     = s_vertices[3 * index]     + pos.x + CHUNK_SIZE_X * chunk->position.x;
            chunk->vertices[3 * i + vertex_offset + 1] = s_vertices[3 * index + 1] + pos.y + CHUNK_SIZE_Y * chunk->position.y;
            chunk->vertices[3 * i + vertex_offset + 2] = s_vertices[3 * index + 2] + pos.z + CHUNK_SIZE_Z * chunk->position.z;
        }
        chunk->indices[index_offset]     = vertex_offset / 3;
        chunk->indices[index_offset + 1] = vertex_offset / 3 + 1;
        chunk->indices[index_offset + 2] = vertex_offset / 3 + 2;
        chunk->indices[index_offset + 3] = vertex_offset / 3;
        chunk->indices[index_offset + 4] = vertex_offset / 3 + 2;
        chunk->indices[index_offset + 5] = vertex_offset / 3 + 3;
        vertex_offset += 12;
        index_offset += 6;
    }
    chunk->vertices_size = vertex_offset * sizeof(float);
    chunk->indices_size = index_offset * sizeof(int);
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

    chunk->vao = vao_init();
    chunk->vbo = vbo_init(GL_ARRAY_BUFFER);
    chunk->ebo = vbo_init(GL_ELEMENT_ARRAY_BUFFER);

    chunk_generate_data(chunk);
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

void chunk_generate_data(Chunk* chunk)
{
    for (int x = 0; x < CHUNK_SIZE_X; x+=2)
    {
        for (int y = 0; y < CHUNK_SIZE_Y; y+=2)
        {
            for (int z = 0; z < CHUNK_SIZE_Z; z+=2)
            {
                chunk->data[chunk_index(x, y, z)] = 1;
                chunk->count++;
            }
        }
    }
}

void chunk_vertices(Chunk* chunk)
{
    free(chunk->vertices);
    free(chunk->indices);
    chunk->vertices_size = 0;
    chunk->indices_size = 0;
    chunk->vertices = malloc(chunk->count * 6 * 12 * sizeof(float));
    assert(chunk->vertices != NULL);
    chunk->indices  = malloc(chunk->count * 6 * 6 * sizeof(int));
    assert(chunk->indices != NULL);
    for (int i = 0; i < CHUNK_VOLUME; i++)
    {
        if (chunk->data[i] == 1)
            fill_vertices(chunk, chunk_block_position(i));
    }
    if (chunk->vertices_size > 0)
    {
        chunk->vertices = realloc(chunk->vertices, chunk->vertices_size);
        chunk->indices = realloc(chunk->indices, chunk->indices_size);
        assert(chunk->vertices != NULL);
        assert(chunk->indices != NULL);

        vao_bind(chunk->vao);
        vbo_bind(chunk->vbo);
        vbo_bind(chunk->ebo);
        vbo_buffer(chunk->vbo, chunk->vertices_size, chunk->vertices);
        vbo_buffer(chunk->ebo, chunk->indices_size, chunk->indices);
    }
}

void chunk_render(Chunk chunk)
{
    vao_bind(chunk.vao);
    vbo_bind(chunk.vbo);
    vbo_bind(chunk.ebo);
    vao_attr();
    glDrawElements(GL_TRIANGLES, chunk.count * 36, GL_UNSIGNED_INT, 0);
}