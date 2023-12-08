#include "renderer.h"

Renderer renderer;

void renderer_init(vec2f viewport_size)
{
    renderer.shader = shader_init("src/shaders/vertex.sl", "src/shaders/fragment.sl");
    shader_use(renderer.shader);
    renderer.vao = vao_init();
    vao_bind(renderer.vao);
    renderer.vbo = vbo_init();
    vbo_bind(renderer.vbo);
    float vertices[18] = {
        0.5, 0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0
    };
    vbo_link(renderer.vbo, vertices);
    camera_init(&(renderer.camera), (float)viewport_size.x / viewport_size.y);
    shader_link_camera(renderer.shader, &(renderer.camera));
}

void render()
{
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
    glDrawArrays(GL_TRIANGLES, 0, 6);
}