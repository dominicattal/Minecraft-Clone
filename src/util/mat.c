#include "mat.h"
#include <stdio.h>

mat4f mat4f_init()
{
    mat4f mat = malloc(16 * sizeof(f32));
    mat[0]  = 1; mat[1]  = 0; mat[2]  = 0; mat[3]  = 0;
    mat[4]  = 0; mat[5]  = 1; mat[6]  = 0; mat[7]  = 0;
    mat[8]  = 0; mat[9]  = 0; mat[10] = 1; mat[11] = 0;
    mat[12] = 0; mat[13] = 0; mat[14] = 0; mat[15] = 1;
    return mat;
}

void mat4f_destroy(mat4f mat)
{
    free(mat);
}

void mat4f_view_matrix(mat4f m, vec3f r, vec3f u, vec3f f, vec3f p)
{
    float k1 = p.x * r.x + p.y * r.y + p.z * r.z;
    float k2 = p.x * u.x + p.y * u.y + p.z * u.z;
    float k3 = p.x * f.x + p.y * f.y + p.z * f.z;
    m[0]  = r.x; m[1]  = u.x; m[2]  = f.x; m[3]  = 0;
    m[4]  = r.y; m[5]  = u.y; m[6]  = f.y; m[7]  = 0;
    m[8]  = r.z; m[9]  = u.z; m[10] = f.z; m[11] = 0;
    m[12] = -k1; m[13] = -k2; m[14] = -k3; m[15] = 1;
}

void mat4f_proj_matrix(mat4f m, f32 ar, f32 fov, f32 ncd, f32 fcd)
{
    f32 a, b, c, d;
    a = 1 / (ar * tan(fov / 2));
    b = 1 / (tan(fov / 2));
    c = (-ncd-fcd) / (ncd - fcd);
    d = (2 * fcd * ncd) / (ncd - fcd);
    m[0]  = a; m[1]  = 0; m[2]  = 0; m[3]  = 0;
    m[4]  = 0; m[5]  = b; m[6]  = 0; m[7]  = 0;
    m[8]  = 0; m[9]  = 0; m[10] = c; m[11] = 1;
    m[12] = 0; m[13] = 0; m[14] = d; m[15] = 0;
}