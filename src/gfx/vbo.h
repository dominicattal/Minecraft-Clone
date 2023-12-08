#ifndef VBO_H
#define VBO_H

#include "gfx.h"

struct VBO
{
    float* data;
    unsigned int ID;
};

typedef struct VBO VBO;

VBO vbo_init();
void vbo_bind(VBO vbo);
void vbo_link(VBO vbo, float* data);

#endif