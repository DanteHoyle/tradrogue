#pragma once

// Seed the game's random number generator from a string
void randseed(const char *seed);

// Generate a random integer from [min, max] (inclusive)
int randint(int min, int max);
