#pragma once

struct game_config {
	const char *player_name;
	const char *log_path;
};

void game_init(struct game_config config);
void game_run(void);
