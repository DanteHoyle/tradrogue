#include "entity.h"

#include "monster.h"

#define PLAYER_INIT_HP		25
#define PLAYER_INIT_ATTACK	10
#define PLAYER_DEFAULT_NAME	"Barkley"
#define PLAYER_RUNE		'@'

void entity_init_player(struct entity *e, int x, int y, const char *name)
{
	*e = (struct entity){
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
void entity_init_monster(struct entity *e, int x, int y, int monster_type)
{
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
void entity_init_item(struct entity *e, int x, int y);
