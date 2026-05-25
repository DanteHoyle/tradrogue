#include "game.h"
#include "log.h"
#include <stdio.h>


int main(void)
{
	FILE *log_file = fopen("game.log", "a");
	if (!log_file) {
		perror("Failed to open log file");
		return 1;
	}

	log_set_file(log_file);

	struct game_state gs = {};

	game_init(&gs, "Player", log_file);
	game_run(&gs);

	fclose(log_file);
}
