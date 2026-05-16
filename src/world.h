#pragma once

#include "entity.h"

#define ENTITY_MAX	128

// World struct holds all entities
// Player is always index 0
struct world {
	struct entity entities[ENTITY_MAX];
	int count;
};

void world_init(struct world *w);
