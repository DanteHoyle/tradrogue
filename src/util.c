#include "util.h"

#include "ui.h"

#include <ncurses.h>

void vector_from_direction(enum direction dir, int *dx, int *dy)
{
	switch (dir) {
        case DIR_N:
		*dx = 0;
		*dy = -1;
		break;
        case DIR_S:
		*dx = 0;
		*dy = 1;
		break;
        case DIR_W:
		*dx = -1;
		*dy = 0;
		break;
        case DIR_E:
		*dx = 1;
		*dy = 0;
		break;
        case DIR_NW:
		*dx = -1;
		*dy = -1;
		break;
        case DIR_NE:
		*dx = 1;
		*dy = -1;
		break;
        case DIR_SW:
		*dx = -1;
		*dy = 1;
		break;
        case DIR_SE:
		*dx = 1;
		*dy = 1;
		break;
        }
}

void exit_game(void)
{
	ui_destroy();
}
