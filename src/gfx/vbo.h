#ifndef VBO_H
#define VBO_H

#include "gfx.h"

struct VBO
{
    unsigned int ID;
};

typedef struct VBO VBO;

VBO vbo_init();
void vbo_bind(VBO vbo);

#endif