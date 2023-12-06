#ifndef SHADER_H
#define SHADER_H

#include "gfx.h"
#include "../util/util.h"

struct Shader
{
    unsigned int ID;
};

typedef struct Shader Shader;

Shader shader_init(char* vs_path, char* fs_path);
void shader_use(Shader shader);

#endif