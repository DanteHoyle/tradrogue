#include "monster.h"

#define DEFINE_STRING_ARRAY(name, ...) name,
#define DEFINE_RUNE_ARRAY(name, rune, ...) rune,
#define DEFINE_HEALTH_ARRAY(name, rune, hp, ...) hp,
#define DEFINE_ATTACK_ARRAY(name, rune, hp, attack) attack,

static const char *string_table[] = { MONSTER_TABLE(DEFINE_STRING_ARRAY) };
static const char rune_table[] = { MONSTER_TABLE(DEFINE_RUNE_ARRAY) };
static int hp_table[] = { MONSTER_TABLE(DEFINE_HEALTH_ARRAY) };
static int attack_table[] = { MONSTER_TABLE(DEFINE_ATTACK_ARRAY) };

static bool is_valid_monster_type(int monster_type)
{
	return monster_type < 0 || monster_type >= MONSTER_TYPE_COUNT;
}

const char *monster_name(int monster_type)
{
	return is_valid_monster_type(monster_type) ? string_table[monster_type] : "MissingName";
}
char monster_rune(int monster_type)
{
	return is_valid_monster_type(monster_type) ? rune_table[monster_type] : '?';
}

int monster_default_attack(int monster_type)
{
	return is_valid_monster_type(monster_type) ? attack_table[monster_type] : -1;
}

int monster_default_hp(int monster_type)
{
	return is_valid_monster_type(monster_type) ? hp_table[monster_type] : -1;
}
