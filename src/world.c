#include "world.h"
#include <assert.h>
#include <string.h>
#include <ncurses.h>
#include "ai.h"
#include "entity.h"
#include "ui.h"
#include "log.h"
#include "monster.h"
#include "exit.h"

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

	return &w->entities[w->count++];
}

void world_reset(struct world *w)
{
	memset(w, 0, sizeof(struct world));
}

void world_update(struct world *w)
{
	for (int i = 0; i < w->count; i++) {
		struct entity *e = &w->entities[i];
		if (e->type != ENTITY_MONSTER)
			continue;
		ai_next_action(e);
	}
}

void world_render(struct world *w)
{
	// Draw the screen
	clear();

	for (int i = 0; i < w->count; i++) {
		struct entity *e = &w->entities[i];
		if (e->type == ENTITY_NONE)
			continue;
		ui_draw_entity(e);
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
