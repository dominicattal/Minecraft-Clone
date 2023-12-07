#include "mat.h"

mat4f mat4f_init()
{
    float* mat = malloc(16 * sizeof(float));
    return mat;
}

void mat4f_free(mat4f mat)
{
    free(mat);
}