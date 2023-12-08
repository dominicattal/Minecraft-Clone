#include "mat.h"

mat4f mat4f_init()
{
    /*
    0 1 2 3
    4 5 6 7
    8 9 A B
    C D E F
    */
    mat4f mat = malloc(16 * sizeof(float));
    mat[0]  = 1; mat[1]  = 0; mat[2]  = 0; mat[3]  = 0;
    mat[4]  = 0; mat[5]  = 1; mat[6]  = 0; mat[7]  = 0;
    mat[8]  = 0; mat[9]  = 0; mat[10] = 1; mat[11] = 0;
    mat[12] = 0; mat[13] = 0; mat[14] = 0; mat[15] = 1;
    return mat;
}

void mat4f_view_matrix(mat4f m, vec3f r, vec3f u, vec3f f, vec3f p)
{
    float k1 = p.x * r.x + p.y * r.y + p.z * r.z;
    float k2 = p.x * u.x + p.y * u.y + p.z * u.z;
    float k3 = p.x * f.x + p.y * f.y + p.z * f.z;
    m[0]  = r.x; m[1]  = u.x; m[2]  = f.x; m[3]  = 0;
    m[4]  = r.y; m[5]  = u.y; m[6]  = f.y; m[7]  = 0;
    m[8]  = r.z; m[9]  = u.z; m[10] = f.z; m[11] = 0;
    m[12] =  k1; m[13] =  k2; m[14] =  k3; m[15] = 1;
}