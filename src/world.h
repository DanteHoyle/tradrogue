#pragma once

#include "entity.h"

// A world is a list of entities
struct world {
	struct entity entities[MAX_ENTITIES];
	int count;
	struct entity *player;
};


// Reset a world to a default state
void world_reset(struct world *w);

void world_update(struct world *w);
void world_render(struct world *w);

void world_create_player(struct world *w, int x, int y, const char *name);
void world_create_monster(struct world *w, int x, int y, int monster_type);
void world_create_item(struct world *w, int x, int y);
