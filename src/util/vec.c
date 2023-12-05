#include "vec.h"

// vec2f
void vec2f_init(vec2f* p_vec, float x, float y)
{
    p_vec->x = x;
    p_vec->y = y;
}

// vec2i
void vec2i_init(vec2i* p_vec, int x, int y)
{
    p_vec->x = x;
    p_vec->y = y;
}

// vec3f
void vec3f_init(vec3f* p_vec, float x, float y, float z)
{
    p_vec->x = x;
    p_vec->y = y;
    p_vec->z = z;
}

// vec3i
void vec3i_init(vec3i* p_vec, int x, int y, int z)
{
    p_vec->x = x;
    p_vec->y = y;
    p_vec->z = z;
}