#ifndef VAO_H
#define VAO_H

#include "gfx.h"

struct VAO
{
    unsigned int ID;
};

typedef struct VAO VAO;

VAO vao_init();
void vao_bind(VAO vao);

#endif