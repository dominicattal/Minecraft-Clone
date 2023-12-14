#ifndef MAT_H
#define MAT_H

#include <stdlib.h>
#include <math.h>
#include "type.h"
#include "vec.h"

typedef f32* mat4f;

mat4f mat4f_init();
void mat4f_destroy(mat4f mat);
void mat4f_view_matrix(mat4f mat, vec3f right, vec3f up, vec3f facing, vec3f position);
void mat4f_proj_matrix(mat4f mat, f32 aspect_ratio, f32 fov, f32 near_clip_distance, f32 far_clip_distance);

#endif