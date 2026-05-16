#pragma once

#include "entity.h"

enum USER_ACTION {
	ACT_NONE,

	ACT_GO_N,
	ACT_GO_S,
	ACT_GO_E,
	ACT_GO_W,
	// ACT_GO_NE,
	// ACT_GO_NW,
	// ACT_GO_SE,
	// ACT_GO_SW,
	//
	// ACT_WAIT,
	// ACT_DRINK,
	// ACT_READ,

	ACT_QUIT
};

// Initializes curses, and sets up logger to use a file
void ui_init(const char *log_path);
// Destroys ncurses and closes the log file
void ui_destroy(void);

void ui_draw_entity(struct entity *e);

enum USER_ACTION ui_wait_for_action(void);

