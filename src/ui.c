#include "ui.h"

#include <ncurses.h>
#include <stdio.h>
#include <assert.h>

#include "entity.h"
#include "log.h"

static FILE *log_file;

static enum USER_ACTION wait_for_action(void)
{
	int ch = getch();

	switch (ch) {
		case 'h': case KEY_LEFT: return ACT_GO_W;
		case 'j': case KEY_DOWN: return ACT_GO_S;
		case 'k': case KEY_UP: return ACT_GO_N;
		case 'l': case KEY_RIGHT: return ACT_GO_E;
		case 'Q': return ACT_QUIT;
	}

	return ACT_NONE;
}

static bool is_onscreen(int x, int y)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);

	return ((x > 0) && (x < max_x)) && ((y > 0) && (y < max_y));
}

void ui_init(const char *log_path)
{
	assert(log_path != nullptr);

	log_file = fopen(log_path, "a");
	log_set_output(log_file);
	LOG_INFO("Logging moved to file named '%s'", log_path);

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, FALSE);
}

void ui_destroy(void)
{
	endwin();
	fclose(log_file);
}

void ui_draw_entity(struct entity *e)
{
	if (is_onscreen(e->x, e->y))
		mvaddch(e->y, e->x, e->rune);
}


 enum USER_ACTION ui_wait_for_action(void)
{
	enum USER_ACTION action = wait_for_action();
	LOG_DEBUG("Read action: %d", action);
	return action;
}
