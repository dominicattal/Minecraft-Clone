#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "type.h"

struct vec2f { f32 x, y; };
struct vec2i { s32 x, y; };
struct vec3f { f32 x, y, z; };
struct vec3i { s32 x, y, z; };

typedef struct vec2f vec2f;
typedef struct vec2i vec2i;
typedef struct vec3f vec3f;
typedef struct vec3i vec3i;

void vec2f_init(vec2f* p_vec, f32 x, f32 y);
void vec2i_init(vec2i* p_vec, s32 x, s32 y);
void vec3f_init(vec3f* p_vec, f32 x, f32 y, f32 z);
void vec3i_init(vec3i* p_vec, s32 x, s32 y, s32 z);

vec3i vec3i_initr(s32 x, s32 y, s32 z);

void vec2f_init0(vec2f* p_vec);
void vec2i_init0(vec2i* p_vec);
void vec3f_init0(vec3f* p_vec);
void vec3i_init0(vec3i* p_vec);

void vec2f_normalize_ip(vec2f* p_vec);
void vec2i_normalize_ip(vec2i* p_vec);
void vec3f_normalize_ip(vec3f* p_vec);
void vec3i_normalize_ip(vec3i* p_vec);

void vec2f_scale_ip(vec2f* p_vec, f32 scale);
void vec2i_scale_ip(vec2i* p_vec, f32 scale);
void vec3f_scale_ip(vec3f* p_vec, f32 scale);
void vec3i_scale_ip(vec3i* p_vec, f32 scale);

void vec3f_norm_scale_ip(vec3f* p_vec, f32 scale);

void vec3f_add_ip(vec3f* p_vec, vec3f vec);

vec3f vec3f_scale(const vec3f vec, f32 scale);

vec3f vec3f_add(const vec3f vec1, const vec3f vec2);
vec3i vec3i_add(const vec3i vec1, const vec3i vec2);

vec3f vec3f_cross(const vec3f vec1, const vec3f vec2);

void vec3f_print(const vec3f vec);
void vec3i_print(const vec3i vec);

#endif