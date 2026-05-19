#pragma once

typedef enum {
	TILE_EMPTY,
	TILE_FLOOR,
	TILE_WALL,
	TILE_DOOR,
	TILE_COUNT
} tile_t;

struct tile_data {
	const char *name;
	char rune;
	bool solid;
};

const struct tile_data *get_tile_data(tile_t type);
