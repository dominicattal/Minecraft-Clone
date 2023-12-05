#include "vec.h"

void vec2f_init(vec2f* p_vec2f, float x, float y)
{
    p_vec2f->x = x;
    p_vec2f->y = y;
}

void vec2i_init(vec2i* p_vec2i, int x, int y)
{
    p_vec2i->x = x;
    p_vec2i->y = y;
}

void vec3f_init(vec3f* p_vec3f, float x, float y, float z)
{
    p_vec3f->x = x;
    p_vec3f->y = y;
    p_vec3f->z = z;
}

void vec3i_init(vec3i* p_vec3i, int x, int y, int z)
{
    p_vec3i->x = x;
    p_vec3i->y = y;
    p_vec3i->z = z;
}