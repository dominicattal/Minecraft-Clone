#ifndef SHADER_H
#define SHADER_H

#include "gfx.h"
#include "texture.h"
#include "../util/util.h"

struct Shader
{
    unsigned int ID;
};

typedef struct Shader Shader;

Shader shader_init(char* vs_path, char* fs_path);
void shader_use(Shader shader);
void shader_link_camera(Shader shader, Camera* camera);
void shader_set_texture(Shader shader, Texture texture);

#endif