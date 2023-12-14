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

void vec2f_normalize_ip(vec2f* p_vec)
{
    float x, y, mag;
    x = p_vec->x;
    y = p_vec->y;
    mag = sqrt(x*x + y*y);
    if (mag != 0)
    {
        p_vec->x /= mag;
        p_vec->y /= mag;
    }
}

void vec2f_scale_ip(vec2f* p_vec, float scale)
{
    p_vec->x *= scale;
    p_vec->y *= scale;
}

// vec2i
void vec2i_init(vec2i* p_vec, s32 x, s32 y)
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

vec3f vec3f_scale(const vec3f vec, float scale)
{
    vec3f ret;
    ret.x = vec.x * scale;
    ret.y = vec.y * scale;
    ret.z = vec.z * scale;
    return ret;
}

vec3f vec3f_add(const vec3f vec1, const vec3f vec2)
{
    vec3f ret;
    ret.x = vec1.x + vec2.x;
    ret.y = vec1.y + vec2.y;
    ret.z = vec1.z + vec2.z;
    return ret;
}

vec3f vec3f_cross(const vec3f vec1, const vec3f vec2)
{
    vec3f ret;
    ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
    ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
    ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
    return ret;
}

void vec3f_print(const vec3f vec)
{
    printf("(%.2f, %.2f, %.2f)\n", vec.x, vec.y, vec.z);
}

// vec3i
void vec3i_init(vec3i* p_vec, s32 x, s32 y, s32 z)
{
    p_vec->x = x;
    p_vec->y = y;
    p_vec->z = z;
}

vec3i vec3i_initr(s32 x, s32 y, s32 z)
{
    vec3i vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}

void vec3i_init0(vec3i* p_vec)
{
    p_vec->x = 0;
    p_vec->y = 0;
    p_vec->z = 0;
}

void vec3i_sub_ip(vec3i* p_vec, vec3i vec)
{
    p_vec->x -= vec.x;
    p_vec->y -= vec.y;
    p_vec->z -= vec.z;
}

void vec3i_print(const vec3i vec)
{
    printf("(%d, %d, %d)\n", vec.x, vec.y, vec.z);
}