#include "game.h"
#include "entity.h"
#include "log.h"
#include "world.h"
#include "ui.h"
#include "map.h"
#include "random.h"

#include <assert.h>

static void handle_action(struct game_state *gs, action_t action)
{
	switch (action) {
	case ACT_GO_N:
		entity_move_dir(&gs->map, gs->world.player, DIR_N);
		break;
	case ACT_GO_S:
		entity_move_dir(&gs->map, gs->world.player, DIR_S);
		break;
	case ACT_GO_E:
		entity_move_dir(&gs->map, gs->world.player, DIR_E);
		break;
	case ACT_GO_W:
		entity_move_dir(&gs->map, gs->world.player, DIR_W);
		break;
        case ACT_GO_NE:
		entity_move_dir(&gs->map, gs->world.player, DIR_NE);
		break;
        case ACT_GO_NW:
		entity_move_dir(&gs->map, gs->world.player, DIR_NW);
		break;
        case ACT_GO_SE:
		entity_move_dir(&gs->map, gs->world.player, DIR_SE);
		break;
        case ACT_GO_SW:
		entity_move_dir(&gs->map, gs->world.player, DIR_SW);
		break;
	case ACT_QUIT:
		gs->running = false;
		break;
	case ACT_NONE:
		break;
        }
}

void game_init(struct game_state *gs, const char *player_name, FILE *log_file)
{
	assert(player_name != nullptr);
	assert(log_file != nullptr);

	LOG_DEBUG("Initializing the game");
	
	gs->dungeon_level = 1;

	log_set_file(log_file);
	ui_init();
	random_seed();
	world_reset(&gs->world);
	map_init(&gs->map, gs->dungeon_level);
	world_create_player(&gs->world, 10, 10, player_name);

	LOG_DEBUG("Finished initializing game");
}

enum game_run_result game_run(struct game_state *gs)
{
	gs->running = true;

	while (gs->running) {
		world_update(&gs->world);
		ui_draw_screen(&gs->world, &gs->map);

		// Get player input
		action_t action = ui_wait_for_action();
		handle_action(gs, action);
	}

	exit_game();

	return EXIT_QUIT;
}
