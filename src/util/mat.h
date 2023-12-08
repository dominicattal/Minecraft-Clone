#ifndef MAT_H
#define MAT_H

#include <stdlib.h>
#include <math.h>
#include "vec.h"

typedef float* mat4f;

mat4f mat4f_init();
void mat4f_view_matrix(mat4f mat, vec3f right, vec3f up, vec3f facing, vec3f position);
void mat4f_proj_matrix(mat4f mat, float aspect_ratio, float fov, float near_clip_distance, float far_clip_distance);

#endif