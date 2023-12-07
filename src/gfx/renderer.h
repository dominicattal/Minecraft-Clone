#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "vao.h"
#include "vbo.h"

struct Renderer
{
    Shader shader;
    VAO vao;
    VBO vbo;
};

typedef struct Renderer Renderer;

void renderer_init();
void render();

#endif