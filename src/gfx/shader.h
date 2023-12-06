#ifndef SHADER_H
#define SHADER_H

#include "gfx.h"

struct Shader
{
    unsigned int ID;
};

typedef struct Shader Shader;

Shader shader_init(char* vs_path, char* fs_path);

#endif