#pragma once

#include "map.h"
#include "world.h"

typedef enum {
	ACT_NONE,

	ACT_GO_N,
	ACT_GO_S,
	ACT_GO_E,
	ACT_GO_W,
	ACT_GO_NE,
	ACT_GO_NW,
	ACT_GO_SE,
	ACT_GO_SW,

	// ACT_WAIT,
	// ACT_DRINK,
	// ACT_READ,

	ACT_QUIT
} action_t;


// Initializes curses, and sets up logger to use a file
void ui_init(const char *log_path);
// Destroys ncurses and closes the log file
void ui_destroy(void);
// Draw the map, player, monsters, and items to the screen
void ui_draw_screen(struct world *w, struct map *m);
// Get the next action from the player
action_t ui_wait_for_action(void);
