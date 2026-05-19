#pragma once

#include "tile.h"

constexpr int MAP_WIDTH = 80;
constexpr int MAP_HEIGHT = 24;
constexpr int MAP_TILES_LEN = MAP_HEIGHT * MAP_WIDTH;

struct map { tile_t tiles[MAP_TILES_LEN]; };

// Initialize a map with rooms, paths, monsters, and items
void map_init(struct map *m, int dungeon_level);

// View tile properties at (x, y) coordinate on the map
const struct tile_data *map_at(struct map *m, int x, int y);
