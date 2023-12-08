#include "vao.h"

VAO vao_init()
{
    VAO vao;
    glGenVertexArrays(1, &vao.ID);
    return vao;
}

void vao_bind(VAO vao)
{
    glBindVertexArray(vao.ID);
}

void vao_attr()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}