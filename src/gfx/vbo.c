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
    glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
}

void vbo_buffer(VBO vbo, float* data)
{
    glBufferData(GL_ARRAY_BUFFER, 30 * sizeof(float), data, GL_DYNAMIC_DRAW);
}