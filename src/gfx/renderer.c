#include "renderer.h"

Renderer renderer;

void renderer_init(vec2i viewport_size)
{
    renderer.shader = shader_init("src/shaders/vert_block.sl", "src/shaders/frag_block.sl");
    shader_use(renderer.shader);

    world_init(renderer.shader, viewport_size);

    Texture tex = texture_init("assets/blockatlas.png");
    shader_set_texture(renderer.shader, tex);
    texture_bind(tex);
}

void renderer_render()
{
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    world_render(); 
}

