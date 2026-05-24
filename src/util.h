#pragma once

// Cardinal Directions
#include "vec2.h"
enum direction {
	DIR_N = 0,
	DIR_S,
	DIR_W,
	DIR_E,
	DIR_NW,
	DIR_NE,
	DIR_SW,
	DIR_SE,
	DIR_COUNT
};

const struct vec2 *dir_to_vec2(enum direction dir);

void exit_game(void);
