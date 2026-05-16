#include "ai.h"
#include "random.h"
#include "entity.h"
#include "ui.h"
#include <ncurses.h>

static bool running = true;
static struct entity entites[5];

int main(void)
{
	ui_init("game.log");
	randseed("Seed");

	struct entity *player = &entites[0];
	entity_init_player(player, 10, 10, nullptr);

	for (int i = 1; i < 5; i ++) {
		entity_init_monster(&entites[i], i * 10, i * 3, i % 3);
	}

	while (running) {
		// Update monster AI
		for (int i = 1; i < 5; i ++) {
			ai_next_action(&entites[i]);
		}

		// Draw the screen
		clear();
		for (int i = 0; i < 5; i ++) {
			ui_draw_entity(&entites[i]);
		}
		refresh();

		// Get player input
		enum USER_ACTION action = ui_wait_for_action();

		switch (action) {
		case ACT_GO_N:
			entity_move(player, 0, -1);
			break;
		case ACT_GO_S:
			entity_move(player, 0, 1);
			break;
		case ACT_GO_E:
			entity_move(player, 1, 0);
			break;
		case ACT_GO_W:
			entity_move(player, -1, 0);
			break;
		case ACT_QUIT:
			running = false;
			break;
		case ACT_NONE:
			break;
		}
	}

	ui_destroy();
}
