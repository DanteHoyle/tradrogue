#include "random.h"
#include <time.h>
#include <stdlib.h>

void randseed(const char *seed)
{ 
	// TODO: Add seeding from a string
	(void)seed;
	srand(time(nullptr));
}

int randint(int min, int max) { return (rand() % (max - min)) + min + 1; }
