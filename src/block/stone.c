#include "block.h"

void stone_init()
{
    Block stone;
    vec2i_init(&stone.tex_coords[BACK],   3, 0);
    vec2i_init(&stone.tex_coords[FRONT],  3, 0);
    vec2i_init(&stone.tex_coords[RIGHT],  3, 0);
    vec2i_init(&stone.tex_coords[LEFT],   3, 0);
    vec2i_init(&stone.tex_coords[TOP],    3, 0);
    vec2i_init(&stone.tex_coords[BOTTOM], 3, 0);
    BLOCKS[STONE] = stone;
}