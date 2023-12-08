#include "vec.h"

// vec2f
void vec2f_init(vec2f* p_vec, float x, float y)
{
    p_vec->x = x;
    p_vec->y = y;
}

void vec2f_init0(vec2f* p_vec)
{
    p_vec->x = 0;
    p_vec->y = 0;
}

// vec2i
void vec2i_init(vec2i* p_vec, int x, int y)
{
    p_vec->x = x;
    p_vec->y = y;
}

void vec2i_init0(vec2i* p_vec)
{
    p_vec->x = 0;
    p_vec->y = 0;
}

// vec3f
void vec3f_init(vec3f* p_vec, float x, float y, float z)
{
    p_vec->x = x;
    p_vec->y = y;
    p_vec->z = z;
}

void vec3f_init0(vec3f* p_vec)
{
    p_vec->x = 0;
    p_vec->y = 0;
    p_vec->z = 0;
}

void vec3f_normalize_ip(vec3f* p_vec)
{
    float x, y, z, mag;
    x = p_vec->x;
    y = p_vec->y;
    z = p_vec->z;
    mag = sqrt(x*x + y*y + z*z);
    if (mag != 0)
    {
        p_vec->x /= mag;
        p_vec->y /= mag;
        p_vec->z /= mag;
    }
}

void vec3f_scale_ip(vec3f* p_vec, float scale)
{
    p_vec->x *= scale;
    p_vec->y *= scale;
    p_vec->z *= scale;
}

void vec3f_norm_scale_ip(vec3f* p_vec, float scale)
{
    vec3f_normalize_ip(p_vec);
    vec3f_scale_ip(p_vec, scale);
}

void vec3f_add_ip(vec3f* p_vec, vec3f vec)
{
    p_vec->x += vec.x;
    p_vec->y += vec.y;
    p_vec->z += vec.z;
}

vec3f vec3f_add(const vec3f vec1, const vec3f vec2)
{
    vec3f ret;
    ret.x = vec1.x + vec2.x;
    ret.y = vec1.y + vec2.y;
    ret.z = vec1.z + vec2.z;
    return ret;
}

// vec3i
void vec3i_init(vec3i* p_vec, int x, int y, int z)
{
    p_vec->x = x;
    p_vec->y = y;
    p_vec->z = z;
}

void vec3i_init0(vec3i* p_vec)
{
    p_vec->x = 0;
    p_vec->y = 0;
    p_vec->z = 0;
}