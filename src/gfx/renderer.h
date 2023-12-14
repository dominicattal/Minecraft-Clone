#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "vao.h"
#include "vbo.h"
#include "texture.h"
#include "../block/block.h"
#include "../util/util.h"
#include "../world/world.h"

struct Renderer
{
    Shader shader;
    World world;
};

typedef struct Renderer Renderer;

void renderer_init(vec2i viewport_size);
void renderer_render();

#endif