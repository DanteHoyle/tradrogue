#include "game.h"


int main(void)
{
	struct game_config config = {
		.seed = "MySeed",
		.player_name = "Dante",
		.log_path = "game.log"
	};

	game_init(config);
	game_run();
}
