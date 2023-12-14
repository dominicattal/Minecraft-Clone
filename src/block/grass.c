#include "block.h"

void grass_init()
{
    Block grass;
    vec2i_init(&grass.tex_coords[BACK],   1, 0);
    vec2i_init(&grass.tex_coords[FRONT],  1, 0);
    vec2i_init(&grass.tex_coords[RIGHT],  1, 0);
    vec2i_init(&grass.tex_coords[LEFT],   1, 0);
    vec2i_init(&grass.tex_coords[TOP],    0, 0);
    vec2i_init(&grass.tex_coords[BOTTOM], 2, 0);
    BLOCKS[GRASS] = grass;
}