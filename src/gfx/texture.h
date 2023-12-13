#ifndef TEXTURE_H
#define TEXTURE_H

#include "gfx.h"
#include "../util/util.h"
#include <stb_image.h>

struct Texture
{
    unsigned int ID;
};

typedef struct Texture Texture;

Texture texture_init(const char* image_path);
void texture_bind(Texture texture);

#endif