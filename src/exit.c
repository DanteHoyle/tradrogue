#include "exit.h"
#include <ncurses.h>
#include "ui.h"

void exit_game(void)
{
	ui_destroy();
}
