#ifndef VEC_H
#define VEC_H

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

#endif