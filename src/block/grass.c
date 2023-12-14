#include "block.h"

void grass_init()
{
    Block grass;
    vec2i_init(&grass.tex_coords[BACK],   0, 0);
    vec2i_init(&grass.tex_coords[FRONT],  0, 0);
    vec2i_init(&grass.tex_coords[RIGHT],  0, 0);
    vec2i_init(&grass.tex_coords[LEFT],   0, 0);
    vec2i_init(&grass.tex_coords[TOP],    0, 0);
    vec2i_init(&grass.tex_coords[BOTTOM], 0, 0);
    BLOCKS[GRASS] = grass;
}