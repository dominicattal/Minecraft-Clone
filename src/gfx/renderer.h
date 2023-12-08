#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "vao.h"
#include "vbo.h"
#include "../block/block.h"
#include "../util/util.h"

struct Renderer
{
    Camera camera;
    Shader shader;
    ht* blocks;
    unsigned int block_modelID;
    VAO vao;
    VBO vbo, ebo; 
};

typedef struct Renderer Renderer;

void renderer_init(vec2i viewport_size);
void renderer_camera_move(vec3f moving, float dt);
void renderer_camera_turn(vec2f offset);
void render_color_blocks();
void render_texture_blocks();
void render();

#endif