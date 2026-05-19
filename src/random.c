#include "random.h"

#include <stdint.h>
#include <time.h>
#include <stdlib.h>

// TODO: Add seeding from a string
void random_seed(void)
{ 
	srand((unsigned int)time(nullptr));
}

int random_int(int min, int max) 
{ 
	return min + rand() % (max+1 - min);
}
