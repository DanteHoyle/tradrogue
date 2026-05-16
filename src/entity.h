#pragma once

typedef enum { ENTITY_PLAYER, ENTITY_MONSTER, ENTITY_ITEM } entity_t;

struct entity {
	entity_t type;
	const char *name;
	char rune;
	int x, y;
	bool alive;

	// Combat stats
	int hp, max_hp;
	int attack;

	// Monster data
	int ai;

	// Item data
	int item_type;
};

void entity_init_player(struct entity *e, int x, int y, const char *name);
void entity_init_monster(struct entity *e, int x, int y, int monster_type);
void entity_init_item(struct entity *e, int x, int y);

void entity_move(struct entity *e, int x, int y);
