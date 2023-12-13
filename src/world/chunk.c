#include "chunk.h"

#pragma region raw_data
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

static unsigned int vertex_idxs[] = {
    0, 1, 2, 0, 2, 3
};
/*
static unsigned int s_tex[] = {
    0, 0,
    0, 1,
    1, 1,
    1, 0
};
*/
static int dirs[] = {
    0, 0, -1,  // -z
    0, 0, 1,  // +z
    1, 0, 0,  // +x
    -1, 0, 0, // -x
    0, 1, 0,  // +y
    0, -1, 0  // -y
};
#pragma endregion

static int vertex_count(Chunk* chunk)
{
    // each face has 4 vertices with 5 components
    // block xyz
    // tex xy
    return chunk->face_count * 4 * 3;
}

static int index_count(Chunk* chunk)
{
    // each face has 2 triangles
    return chunk->face_count * 6;
}

static int max_vertex_count(Chunk* chunk)
{
    return chunk->data_count * 6 * 4 * 3;
}

static int max_index_count(Chunk* chunk)
{
    return chunk->data_count * 6 * 6;
}

static bool has_adjacent(const Chunk* chunk, const vec3i pos, const Side side)
{
    int idx = chunk_index(pos.x + dirs[3*side], pos.y + dirs[3*side+1], pos.z + dirs[3*side+2]);
    if (idx != -1 && chunk->data[idx] == 1)
        return true;
    return false;
}   

static void fill_vertices(Chunk* chunk, vec3i pos)
{
    for (Side side = FIRST_SIDE; side <= LAST_SIDE; side++)
    {
        if (has_adjacent(chunk, pos, side))
            continue;
        
        for (int i = 0; i < 4; i++)
        {
            unsigned int index = side_idxs[4 * side + i];
            chunk->vertices[3 * i + vertex_count(chunk)]     = s_vertices[3 * index]     + pos.x + CHUNK_SIZE_X * chunk->position.x;
            chunk->vertices[3 * i + vertex_count(chunk) + 1] = s_vertices[3 * index + 1] + pos.y + CHUNK_SIZE_Y * chunk->position.y;
            chunk->vertices[3 * i + vertex_count(chunk) + 2] = s_vertices[3 * index + 2] + pos.z + CHUNK_SIZE_Z * chunk->position.z;
            //chunk->vertices[3 * i + vertex_count(chunk) + 3] = s_tex[2 * i];
            //chunk->vertices[3 * i + vertex_count(chunk) + 4] = s_tex[2 * i + 1];
        }

        for (int i = 0; i < 6; i++)
            chunk->indices[index_count(chunk) + i] = vertex_count(chunk) / 3 + vertex_idxs[i];

        chunk->face_count++;
    }
}

void chunk_init(Chunk* chunk, int x, int y, int z)
{
    vec3i position;
    vec3i_init(&position, x, y, z);
    chunk->position = position;
    chunk->data     = malloc(CHUNK_VOLUME * sizeof(int));
    chunk->vertices = malloc(0);
    chunk->indices  = malloc(0);
    chunk->data_count = 0;

    assert(chunk->data != NULL);

    chunk->vao = vao_init();
    chunk->vbo = vbo_init(GL_ARRAY_BUFFER);
    chunk->ebo = vbo_init(GL_ELEMENT_ARRAY_BUFFER);

    chunk_generate_data(chunk);
    chunk_generate_vertices(chunk);
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
                chunk->data_count++;
            }
        }
    }
}

void chunk_generate_vertices(Chunk* chunk)
{
    free(chunk->vertices);
    free(chunk->indices);
    chunk->face_count = 0;
    chunk->vertices = calloc(max_vertex_count(chunk), sizeof(float));
    chunk->indices  = calloc(max_index_count(chunk), sizeof(int));
    assert(chunk->vertices != NULL);
    assert(chunk->indices != NULL);
    for (int i = 0; i < CHUNK_VOLUME; i++)
    {
        if (chunk->data[i] == 1)
            fill_vertices(chunk, chunk_block_position(i));
    }
    if (chunk->face_count * 12 > 0)
    {
        chunk->vertices = realloc(chunk->vertices, vertex_count(chunk) * sizeof(float));
        chunk->indices = realloc(chunk->indices, index_count(chunk) * sizeof(int));
        assert(chunk->vertices != NULL);
        assert(chunk->indices != NULL);

        vao_bind(chunk->vao);
        vbo_bind(chunk->vbo);
        vbo_bind(chunk->ebo);
        vbo_buffer(chunk->vbo, vertex_count(chunk) * sizeof(float), chunk->vertices);
        vbo_buffer(chunk->ebo, index_count(chunk) * sizeof(int), chunk->indices);
    }
}

void chunk_render(Chunk* chunk)
{
    vao_bind(chunk->vao);
    vbo_bind(chunk->vbo);
    vbo_bind(chunk->ebo);
    vao_attr(0, 3, 3 * sizeof(float), 0);
    //vao_attr(1, 2, 2 * sizeof(float), 3 * sizeof(float));
    glDrawElements(GL_TRIANGLES, index_count(chunk), GL_UNSIGNED_INT, 0);
}

void chunk_reload(Chunk* chunk)
{
    chunk_generate_vertices(chunk);
}