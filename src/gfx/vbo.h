#ifndef VBO_H
#define VBO_H

#include "gfx.h"

struct VBO
{
    unsigned int type, ID;
};

typedef struct VBO VBO;

VBO vbo_init();
void vbo_bind(VBO vbo);
void vbo_buffer(VBO vbo, int size, void* data);

#endif