#include "vbo.h"

VBO vbo_init()
{
    VBO vbo;
    glGenBuffers(1, &vbo.ID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    return vbo;
}

void vbo_bind(VBO vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
}

void vbo_link(VBO vbo, float* data)
{
    glBufferData(GL_ARRAY_BUFFER, 30 * sizeof(float), data, GL_DYNAMIC_DRAW);
}