#pragma once

#include "tile.h"

constexpr int MAP_WIDTH = 80;
constexpr int MAP_HEIGHT = 24;
constexpr int MAP_TILES_LEN = MAP_HEIGHT * MAP_WIDTH;

constexpr int MAX_ROOMS_PER_MAP = 3;

struct room_params { int x, y, width, height; };

struct map {
	tile_t tiles[MAP_TILES_LEN];
	struct room_params rooms[MAX_ROOMS_PER_MAP];
	int rooms_used;
};

// Initialize a map with rooms, paths, monsters, and items
void map_init(struct map *m, int dungeon_level);

// View tile properties at (x, y) coordinate on the map
const struct tile_data *map_at(struct map *m, int x, int y);
