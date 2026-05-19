#include "game.h"
#include "entity.h"
#include "world.h"
#include "ui.h"
#include "map.h"
#include "random.h"

static bool running = false;
static struct world world = {};
static struct map map = {};
static int dungeon_level = 1;

static void handle_action(action_t action)
{
	switch (action) {
	case ACT_GO_N:
		entity_move_dir(&map, world.player, DIR_N);
		break;
	case ACT_GO_S:
		entity_move_dir(&map, world.player, DIR_S);
		break;
	case ACT_GO_E:
		entity_move_dir(&map, world.player, DIR_E);
		break;
	case ACT_GO_W:
		entity_move_dir(&map, world.player, DIR_W);
		break;
	case ACT_QUIT:
		running = false;
		break;
	case ACT_NONE:
		break;
        case ACT_GO_NE:
		entity_move_dir(&map, world.player, DIR_NE);
		break;
        case ACT_GO_NW:
		entity_move_dir(&map, world.player, DIR_NW);
		break;
        case ACT_GO_SE:
		entity_move_dir(&map, world.player, DIR_SE);
		break;
        case ACT_GO_SW:
		entity_move_dir(&map, world.player, DIR_SW);
		break;
        }
}

void game_init(struct game_config config)
{
	ui_init(config.log_path);
	randseed(config.seed);
	world_reset(&world);
	map_init(&map, dungeon_level);
	world_create_player(&world, 10, 10, config.player_name);
}

void game_run(void)
{
	running = true;

	while (running) {
		world_update(&world);
		ui_draw_screen(&world, &map);

		// Get player input
		action_t action = ui_wait_for_action();
		handle_action(action);
	}

	exit_game();
}
