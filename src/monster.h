#pragma once

#define MONSTER_BAT	0
#define MONSTER_GOBLIN	1
#define MONSTER_KOBOLD	2
#define MONSTER_TYPE_COUNT 3

const char *monster_name(int monster_type);
char monster_rune(int monster_type);
int monster_default_attack(int monster_type);
int monster_default_hp(int monster_type);
int monster_default_ai(int monster_type);
