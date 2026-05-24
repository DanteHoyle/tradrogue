#include "world.h"
#include <assert.h>
#include <string.h>
#include <ncurses.h>
#include "ai.h"
#include "entity.h"
#include "log.h"
#include "monster.h"

#define PLAYER_INIT_HP		25
#define PLAYER_INIT_ATTACK	10
#define PLAYER_DEFAULT_NAME	"Barkley"
#define PLAYER_RUNE		'@'

static struct entity *new_entity(struct world *w)
{
	if (w->count >= MAX_ENTITIES) {
		LOG_ERROR("Too many entities to create another, MAX_ENTITIES=%d", MAX_ENTITIES);
		exit_game();
	}

	LOG_DEBUG("Adding a new entity to world id=%d", w->count);
	return &w->entities[w->count++];
}

void world_reset(struct world *w)
{
	LOG_DEBUG("Resetting world struct %p", (void *)w);
	memset(w, 0, sizeof(struct world));
}

void world_update(struct world *w)
{
	LOG_DEBUG("Updating entities in world");
	for (int i = 0; i < w->count; i++) {
		struct entity *e = &w->entities[i];
		if (e->type != ENTITY_MONSTER)
			continue;
		ai_next_action(e);
	}
}

void world_create_player(struct world *w, int x, int y, const char *name)
{
	assert(w->player == nullptr);
	w->player = new_entity(w);
	*w->player = (struct entity){
		.type = ENTITY_PLAYER,
		.name = name == nullptr ? PLAYER_DEFAULT_NAME : name,
		.rune = PLAYER_RUNE,
		.x = x, .y = y,

		// Combat stats
		.attack = PLAYER_INIT_ATTACK,
		.hp = PLAYER_INIT_HP,
		.max_hp = PLAYER_INIT_HP
	};
}
void world_create_monster(struct world *w, int x, int y, int monster_type)
{
	struct entity *e = new_entity(w);
	*e = (struct entity){
		.type = ENTITY_MONSTER,
		.name = monster_name(monster_type),
		.rune = monster_rune(monster_type),
		.x = x, .y = y,

		// Combat stats
		.attack = monster_default_attack(monster_type),
		.hp = monster_default_hp(monster_type),
		.max_hp = monster_default_hp(monster_type),
	};
	LOG_DEBUG("Created monster of type %d", monster_type);
}
void world_create_item(struct world *w, int x, int y)
{
	struct entity *e = new_entity(w);
	*e = (struct entity){
		.type = ENTITY_ITEM,
		.x = x, .y = y,
		.rune = '!',
		.item_type = 10
	};

}
