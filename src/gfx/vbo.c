#include "vbo.h"

VBO vbo_init()
{
    VBO vbo;
    glGenBuffers(1, &vbo.ID);
    return vbo;
}

void vbo_bind(VBO vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
}

void vbo_link(VBO vbo, float* data)
{
    vbo_bind(vbo);
    glBufferData(GL_ARRAY_BUFFER, 30 * sizeof(float), data, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}