#include "renderer.h"

Renderer renderer;

float vertices[18] = {
        0.5, 0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0
    };

void renderer_init(vec2i viewport_size)
{
    renderer.shader = shader_init("src/shaders/vertex.sl", "src/shaders/fragment.sl");
    shader_use(renderer.shader);
    renderer.vao = vao_init();
    vao_bind(renderer.vao);
    renderer.vbo = vbo_init(GL_ARRAY_BUFFER);
    vbo_bind(renderer.vbo);
    renderer.ebo = vbo_init(GL_ELEMENT_ARRAY_BUFFER);
    vbo_buffer(renderer.vbo, vertices);
    vao_attr();
    camera_init(&renderer.camera, (float)viewport_size.x / viewport_size.y);
    shader_link_camera(renderer.shader, &renderer.camera);
}

void renderer_camera_move(vec3f direction)
{
    camera_move(&renderer.camera, direction);
}

void renderer_camera_turn(vec2f offset)
{
    camera_turn(&renderer.camera, offset);
}

void render()
{
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
    float vertices[] = {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 1, 0,
        0, 0, 1,
        1, 0, 1,
        1, 1, 1,
        0, 1, 1
    };
    unsigned int indices[] = {
        1, 0, 3, 1, 3, 2, // north (-z)
        4, 5, 6, 4, 6, 7, // south (+z)
        5, 1, 2, 5, 2, 6, // east (+x)
        0, 4, 7, 0, 7, 3, // west (-x)
        2, 3, 7, 2, 7, 6, // top (+y)
        5, 4, 0, 5, 0, 1  // bottom (-y)
    };
    glDrawArrays(GL_TRIANGLES, 0, 6);
}