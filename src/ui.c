#include "ui.h"

#include <ncurses.h>
#include <stdio.h>
#include <assert.h>

#include "entity.h"
#include "log.h"
#include "map.h"

static FILE *log_file;

static bool is_onscreen(int x, int y)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);

	return ((x >= 0) && (x < max_x)) && ((y >= 0) && (y < max_y));
}

void ui_init(const char *log_path)
{
	assert(log_path != nullptr);

	log_file = fopen(log_path, "a");
	log_set_output(log_file);
	LOG_DEBUG("Logging moved to file named '%s'", log_path);

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

void ui_draw_screen(struct world *w, struct map *m)
{
	clear();
	
	// Draw the map
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			mvaddch(y, x, map_at(m, x, y)->rune);
		}
	}
	

	// Draw entities
	for (int i = 0; i < w->count; i++) {
		struct entity *e = &w->entities[i];
		if (e->type == ENTITY_NONE)
			continue;
		ui_draw_entity(e);
        }

	refresh();
}

action_t ui_wait_for_action(void)
{
	int ch = getch();

	switch (ch) {
		case 'h': case KEY_LEFT: return ACT_GO_W;
		case 'j': case KEY_DOWN: return ACT_GO_S;
		case 'k': case KEY_UP: return ACT_GO_N;
		case 'l': case KEY_RIGHT: return ACT_GO_E;
		case 'y': return ACT_GO_NW;
		case 'u': return ACT_GO_NE;
		case 'b': return ACT_GO_SW;
		case 'n': return ACT_GO_SE;
		case 'Q': return ACT_QUIT;
	}

	return ACT_NONE;
}
