#pragma once

#include "map.h"
#include "world.h"
#include <stdio.h>

struct game_config {
	const char *player_name;
	FILE *log_file;
};

void game_init(struct game_config config);
void game_run(void);
