#include "vbo.h"

float vertices[] = {
    0.5f,  0.5f, 0.0f, 
    0.5f, -0.5f, 0.0f, 
    -0.5f,  0.5f, 0.0f,  
    0.5f, -0.5f, 0.0f,  
    -0.5f, -0.5f, 0.0f,  
    -0.5f,  0.5f, 0.0f   
};

VBO vbo_init()
{
    VBO vbo;
    glGenBuffers(1, &vbo.ID);
    return vbo;
}

void vbo_bind(VBO vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo.ID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}