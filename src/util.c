#include "util.h"

#include <assert.h>
#include <ncurses.h>
#include "ui.h"
#include "vec2.h"

constexpr struct vec2 V2_NORTH = { 0, -1 };
constexpr struct vec2 V2_SOUTH = { 0, 1 };
constexpr struct vec2 V2_EAST = { 1, 0 };
constexpr struct vec2 V2_WEST = { -1, 0 };
constexpr struct vec2 V2_NORTH_EAST = { 1, -1 };
constexpr struct vec2 V2_NORTH_WEST = { -1, -1 };
constexpr struct vec2 V2_SOUTH_EAST = { 1, 1 };
constexpr struct vec2 V2_SOUTH_WEST = { -1, 1 };

const struct vec2 *dir_to_vec2(enum direction dir)
{
	assert(dir >= 0 && dir < DIR_COUNT);
	switch(dir) {
        case DIR_N: return &V2_NORTH;
        case DIR_S: return &V2_SOUTH;
        case DIR_W: return &V2_WEST;
        case DIR_E: return &V2_EAST;
        case DIR_NW: return &V2_NORTH_WEST;
        case DIR_NE: return &V2_NORTH_EAST;
        case DIR_SW: return &V2_SOUTH_WEST;
        case DIR_SE: return &V2_SOUTH_EAST;
	default:
		assert(0 && "Invalid Direction");
        }
}

void exit_game(void)
{
	ui_destroy();
}
