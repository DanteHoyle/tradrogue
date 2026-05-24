#pragma once

#include <stdio.h>

struct game_state;

enum game_run_result {
	EXIT_DEAD,
	EXIT_QUIT,
	EXIT_VICTORY,
	EXIT_ERROR
};

struct game_state *game_create(const char *player_name, FILE *log_file);
enum game_run_result game_run(struct game_state *gs);
void game_destroy(struct game_state *gs);
