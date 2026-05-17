#pragma once

#include "util.h"
#define MAX_ENTITIES	128

typedef enum {
	ENTITY_NONE,
	ENTITY_PLAYER,
	ENTITY_MONSTER,
	ENTITY_ITEM
} entity_t;

struct entity {
	entity_t type;
	const char *name;
	char rune;
	int x, y;

	// Combat stats
	int hp, max_hp;
	int attack;

	// Monster data
	int ai;

	// Item data
	int item_type;
};

// Move an entityh by a relative amount
void entity_move_by(struct entity *e, int dx, int dy);
void entity_move_to(struct entity *e, int x, int y);
void entity_move_dir(struct entity *e, enum DIRECTION dir);
