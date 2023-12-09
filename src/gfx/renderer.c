#include "renderer.h"

Renderer renderer;

static void render_chunk(unsigned int idx)
{
    if (renderer.chunks[idx].count == 0)
        return;
    vbo_buffer(renderer.vbo, renderer.chunks[idx].vertices_size, renderer.chunks[idx].vertices);
    //vbo_buffer(renderer.ebo, sizeof(indices), indices);
    vao_attr();
    glDrawArrays(GL_TRIANGLES, 0, renderer.chunks[idx].count * 36);
}

void renderer_init(vec2i viewport_size)
{
    renderer.shader = shader_init("src/shaders/vertex.sl", "src/shaders/fragment.sl");
    shader_use(renderer.shader);
    renderer.vao = vao_init();
    vao_bind(renderer.vao);
    renderer.vbo = vbo_init(GL_ARRAY_BUFFER);
    vbo_bind(renderer.vbo);
    renderer.ebo = vbo_init(GL_ELEMENT_ARRAY_BUFFER);
    vbo_bind(renderer.ebo);

    renderer.chunk_count = 1;
    renderer.chunks = malloc(renderer.chunk_count * sizeof(Chunk));
    for (int i = 0; i < renderer.chunk_count; i++)
        chunk_init(&renderer.chunks[i], i % 10, 0, (i / 10) % 10);

    camera_init(&renderer.camera, (float)viewport_size.x / viewport_size.y);
    shader_link_camera(renderer.shader, &renderer.camera);
}

void renderer_camera_move(vec3f moving, float dt)
{
    camera_move(&renderer.camera, moving, dt);
}

void renderer_camera_turn(vec2f offset)
{
    camera_turn(&renderer.camera, offset);
}

void renderer_render()
{
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    for (int i = 0; i < renderer.chunk_count; i++)
    {
        render_chunk(i);
    }
}