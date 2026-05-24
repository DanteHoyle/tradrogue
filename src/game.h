#pragma once

#include "map.h"
#include "world.h"
#include <stdio.h>

struct game_config {
	const char *player_name;
	FILE *log_file;
};

struct game_state {
	struct world world;
	struct map map;
	int level;
	bool running;
};

void game_init(const struct game_config *config);
void game_run(void);
