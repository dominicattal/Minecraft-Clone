#include "world.h"

World world;

static vec3i camera_chunk_coords()
{
    vec3i chunk_coords;

    if (world.camera.position.x >= 0)
        chunk_coords.x = world.camera.position.x / CHUNK_SIZE_X;
    else
        chunk_coords.x = world.camera.position.x / CHUNK_SIZE_X - 1;
    if (world.camera.position.y >= 0)
        chunk_coords.y = world.camera.position.y / CHUNK_SIZE_Y;
    else
        chunk_coords.y = world.camera.position.y / CHUNK_SIZE_Y - 1;
    if (world.camera.position.z >= 0)
        chunk_coords.z = world.camera.position.z / CHUNK_SIZE_Z;
    else
        chunk_coords.z = world.camera.position.z / CHUNK_SIZE_Z - 1;

    return chunk_coords;
}

void world_init(Shader shader, vec2i viewport_size)
{
    noise_init(0, WORLD_SIZE_X, WORLD_SIZE_Z, CHUNK_SIZE_X, CHUNK_SIZE_Z);

    camera_init(&world.camera, (float)viewport_size.x / viewport_size.y);
    shader_link_camera(shader, &world.camera);

    world.render_distance = 10;
    world.chunk_offset = vec3i_initr(0, 0, 0);
    world.chunks = calloc(WORLD_VOLUME, sizeof(Chunk));
    for (u16 i = 0; i < world.render_distance * world.render_distance; i++)
        chunk_init(&world.chunks[i], i % world.render_distance, 0, (i / world.render_distance) % world.render_distance);
    for (u16 i = 0; i < world.render_distance * world.render_distance; i++)
        chunk_generate_vertices(&world.chunks[i]);
}

void world_render()
{   
    for (int i = 0; i < world.render_distance * world.render_distance; i++)
    {
        chunk_render(&world.chunks[i]);
    }
}

void world_reload()
{
    chunk_reload(&world.chunks[0]);
}

s32 world_chunk_index(vec3i chunk_pos)
{
    if (chunk_pos.x < 0 || chunk_pos.y < 0 || chunk_pos.z < 0) 
        return -1;
    if (chunk_pos.x >= world.render_distance || chunk_pos.y >= 1 || chunk_pos.z >= world.render_distance)
        return -1;
    return chunk_pos.x + world.render_distance * chunk_pos.z;
}

bool world_block_at(vec3i chunk_pos, vec3i block_pos)
{
    // assumed block_pos is 1 block on edge
    if (block_pos.x < 0)
    {
        chunk_pos.x--;
        block_pos.x = CHUNK_SIZE_X - 1;
    }
    if (block_pos.x >= CHUNK_SIZE_X)
    {
        chunk_pos.x++;
        block_pos.x = 0;
    }
    if (block_pos.y < 0)
    {
        chunk_pos.y--;
        block_pos.y = CHUNK_SIZE_Y - 1;
    }
    if (block_pos.y >= CHUNK_SIZE_Y)
    {
        chunk_pos.y++;
        block_pos.y = 0;
    }
    if (block_pos.z < 0)
    {
        chunk_pos.z--;
        block_pos.z = CHUNK_SIZE_Z - 1;
    }
    if (block_pos.z >= CHUNK_SIZE_Z)
    {
        chunk_pos.z++;
        block_pos.z = 0;
    }
    s16 idx = world_chunk_index(chunk_pos);
    if (idx != -1)
    {
        Chunk chunk = world.chunks[idx];
        return chunk.data[chunk_block_index(block_pos.x, block_pos.y, block_pos.z)] != 0;
    }
    return false;
}

void world_camera_move(vec3f moving, f32 dt)
{
    camera_move(&world.camera, moving, dt);
}

void world_camera_turn(vec2f offset)
{
    camera_turn(&world.camera, offset);
}
