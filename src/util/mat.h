#ifndef MAT_H
#define MAT_H

#include <stdlib.h>
#include "vec.h"

typedef float* mat4f;

mat4f mat4f_init();
void mat4f_view_matrix(mat4f m, vec3f r, vec3f u, vec3f f, vec3f p);
void mat4f_proj_matrix(mat4f m, float aspect_ratio);

#endif