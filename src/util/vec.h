#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <stdio.h>

struct vec2f { float x, y; };
struct vec2i { int x, y; };
struct vec3f { float x, y, z; };
struct vec3i { int x, y, z; };

typedef struct vec2f vec2f;
typedef struct vec2i vec2i;
typedef struct vec3f vec3f;
typedef struct vec3i vec3i;

void vec2f_init(vec2f* p_vec, float x, float y);
void vec2i_init(vec2i* p_vec, int x, int y);
void vec3f_init(vec3f* p_vec, float x, float y, float z);
void vec3i_init(vec3i* p_vec, int x, int y, int z);

vec3i vec3i_initr(int x, int y, int z);

void vec2f_init0(vec2f* p_vec);
void vec2i_init0(vec2i* p_vec);
void vec3f_init0(vec3f* p_vec);
void vec3i_init0(vec3i* p_vec);

void vec2f_normalize_ip(vec2f* p_vec);
void vec2i_normalize_ip(vec2i* p_vec);
void vec3f_normalize_ip(vec3f* p_vec);
void vec3i_normalize_ip(vec3i* p_vec);

void vec2f_scale_ip(vec2f* p_vec, float scale);
void vec2i_scale_ip(vec2i* p_vec, float scale);
void vec3f_scale_ip(vec3f* p_vec, float scale);
void vec3i_scale_ip(vec3i* p_vec, float scale);

void vec3f_norm_scale_ip(vec3f* p_vec, float scale);

void vec3f_add_ip(vec3f* p_vec, vec3f vec);

vec3f vec3f_scale(const vec3f vec, float scale);

vec3f vec3f_add(const vec3f vec1, const vec3f vec2);

vec3f vec3f_cross(const vec3f vec1, const vec3f vec2);

void vec3f_print(const vec3f vec);
void vec3i_print(const vec3i vec);

#endif