#include "noise.h"

#define PI 3.141592653589

static f32* angles;
static s16 world_size_x;
static s16 world_size_z;
static s16 chunk_size_x;
static s16 chunk_size_z;

static f32 random_angle()
{
    return ((f64) rand() / (f64)RAND_MAX) * PI * 2;
}

static f32 interpolate(f32 a0, f32 a1, f32 w)
{
    if (0.0 > w) return a0;
    if (1.0 < w) return a1;
    return (a1 - a0) * ((w * (w * 6.0 - 15.0) + 10.0) * w * w * w) + a0;
}

void noise_init(s32 seed, s16 world_x, s16 world_z, s16 chunk_x, s16 chunk_z)
{
    angles = malloc((world_x+1)*(world_z+1) * sizeof(f32));
    world_size_x = world_x;
    world_size_z = world_z;
    chunk_size_x = chunk_x;
    chunk_size_z = chunk_z;
    srand(seed);
    for (int i = 0; i < (world_size_x+1)*(world_size_z+1); i++)
    {
        angles[i] = random_angle();
    }
}

static f32 dot_gradient(s32 ix, s32 iz, f32 x, f32 z)
{
    vec2f gradient = vec2f_inita(angles[ix + (world_size_x + 1) * iz]);
    f32 dx = x - ix;
    f32 dz = z - iz;
    return dx * gradient.x + dz * gradient.y;
}

u8 noise_at(vec3i chunk_pos, vec3i block_pos)
{
    s32 x0, x1, z0, z1;
    f32 x, z, sx, sz;
    x0 = chunk_pos.x;
    x1 = chunk_pos.x + 1;
    z0 = chunk_pos.z;
    z1 = chunk_pos.z + 1;
    sx = (f32)block_pos.x / chunk_size_x;
    sz = (f32)block_pos.z / chunk_size_z;
    x = x0 + sx;
    z = z0 + sz;

    f32 n0, n1, ix0, ix1, value;
    n0 = dot_gradient(x0, z0, x, z);
    n1 = dot_gradient(x1, z0, x, z);
    ix0 = interpolate(n0, n1, sx);
    n0 = dot_gradient(x0, z1, x, z);
    n1 = dot_gradient(x1, z1, x, z);
    ix1 = interpolate(n0, n1, sx);
    value = interpolate(ix0, ix1, sz) + 1;
    return (s8) (value * 50);
}