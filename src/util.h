#pragma once

enum direction {
	DIR_N,
	DIR_S,
	DIR_W,
	DIR_E,
	DIR_NW,
	DIR_NE,
	DIR_SW,
	DIR_SE
};

void vector_from_direction(enum direction dir, int *dx, int *dy);

void exit_game(void);
