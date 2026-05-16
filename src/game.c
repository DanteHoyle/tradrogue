#include "game.h"
#include "exit.h"
#include "ui.h"
#include "random.h"

static bool running = false;
static struct world world;

static void handle_action(enum USER_ACTION action)
{
	switch (action) {
	case ACT_GO_N:
		entity_move_by(world.player, 0, -1);
		break;
	case ACT_GO_S:
		entity_move_by(world.player, 0, 1);
		break;
	case ACT_GO_E:
		entity_move_by(world.player, 1, 0);
		break;
	case ACT_GO_W:
		entity_move_by(world.player, -1, 0);
		break;
	case ACT_QUIT:
		running = false;
		break;
	case ACT_NONE:
		break;
	}

}

void game_init(struct game_config config)
{
	ui_init(config.log_path);
	randseed(config.seed);
	world_reset(&world);
	world_create_player(&world, 10, 10, config.player_name);
}

void game_run(void)
{
	running = true;

	while (running) {
		world_update(&world);
		world_render(&world);

		// Get player input
		enum USER_ACTION action = ui_wait_for_action();
		handle_action(action);
	}

	exit_game();
}
