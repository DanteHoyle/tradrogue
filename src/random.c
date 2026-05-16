#include "random.h"
#include <time.h>
#include <stdlib.h>
#include "log.h"

void randseed(const char *seed)
{ 
	// TODO: Add seeding from a string
	LOG_INFO("Seeding RNG with: '%s'", seed);
	(void)seed;
	srand(time(nullptr));
}

int randint(int min, int max) 
{ 
	return rand() % (max + 1 - min) + min;
}
