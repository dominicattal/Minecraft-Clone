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

void vao_attr(int index, int count, int size, void* offset)
{
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, size, offset);
    glEnableVertexAttribArray(index);
}