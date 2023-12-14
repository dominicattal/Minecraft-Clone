#include "block.h"

void stone_init()
{
    Block stone;
    vec2i_init(&stone.tex_coords[BACK],   1, 0);
    vec2i_init(&stone.tex_coords[FRONT],  1, 0);
    vec2i_init(&stone.tex_coords[RIGHT],  1, 0);
    vec2i_init(&stone.tex_coords[LEFT],   1, 0);
    vec2i_init(&stone.tex_coords[TOP],    1, 0);
    vec2i_init(&stone.tex_coords[BOTTOM], 1, 0);
    BLOCKS[STONE] = stone;
}