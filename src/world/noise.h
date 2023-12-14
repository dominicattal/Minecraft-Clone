#ifndef NOISE_H
#define NOISE_H

#include "../util/util.h"

void noise_init(s32 seed, s16 world_x, s16 world_z, s16 chunk_x, s16 chunk_z);
u8 noise_at(vec3i chunk_pos, vec3i block_pos);

#endif