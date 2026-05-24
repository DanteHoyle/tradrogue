#include "game.h"
#include <stdio.h>


int main(void)
{
	FILE *log = fopen("game.log", "a");
	if (!log) {
		perror("Failed to open log file");
		return 1;
	}

	struct game_config config = {
		.player_name = "Dante",
		.log_file = log
	};

	game_init(&config);
	game_run();

	fclose(log);
}
