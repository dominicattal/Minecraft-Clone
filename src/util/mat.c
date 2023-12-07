#include "mat.h"

mat4f mat4f_init()
{
    /*
    0 1 2 3
    4 5 6 7
    8 9 A B
    C D E F
    */
    float* mat = malloc(16 * sizeof(float));
    mat[0] = 1; mat[5] = 1; mat[10] = 1; mat[15] = 1;
    return mat;
}