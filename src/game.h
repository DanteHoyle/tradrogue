#pragma once

#include <stdio.h>

#include "world.h"
#include "map.h"


struct game_state {
	struct world world;
	struct map map;
	int dungeon_level;
	bool running;
};

enum game_run_result {
	EXIT_DEAD,
	EXIT_QUIT,
	EXIT_VICTORY,
	EXIT_ERROR
};

void game_init(struct game_state *gs, const char *player_name, FILE *log_file);
enum game_run_result game_run(struct game_state *gs);
void game_destroy(struct game_state *gs);
