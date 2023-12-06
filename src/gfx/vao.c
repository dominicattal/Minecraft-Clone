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