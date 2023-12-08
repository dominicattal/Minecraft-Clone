#include "vbo.h"

VBO vbo_init(unsigned int type)
{
    VBO vbo;
    glGenBuffers(1, &vbo.ID);
    vbo.type = type;
    return vbo;
}

void vbo_bind(VBO vbo)
{
    glBindBuffer(vbo.type, vbo.ID);
}

void vbo_buffer(VBO vbo, int size, void* data)
{
    glBufferData(vbo.type, size, data, GL_DYNAMIC_DRAW);
}