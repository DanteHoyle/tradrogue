#include "map.h"

#include "tile.h"
#include "log.h"
#include <assert.h>
#include <string.h>

// Represents a rooms position and size
struct room_params { int x, y, width, height; };

// Helper function to calculate the index of a tile in the map tiles struct
// General usage: m->tiles[index_at(x, y)] to access the tile at (x, y)
static inline int index_at(int x, int y) { return (y * MAP_WIDTH) + x; }

// Create a room on the map
static void mkroom(struct map *m, const struct room_params *r)
{
	assert(m->rooms_used + 1 < MAX_ROOMS_PER_MAP && "the map can't fit anymore rooms");
	LOG_DEBUG("Generating room #%d for dungeon: (%d, %d) %dx%d",
		   m->rooms_used, r->x, r->y, r->width, r->height);
	m->rooms[m->rooms_used++] = *r;

	for (int row = 0; row < r->width; row++) {
		for (int col = 0; col < r->height; col++) {
			bool is_wall = row == 0 || col == 0 || row == r->height - 1 || col == r->width - 1;
			m->tiles[index_at(r->x + col, r->y + row)] = is_wall ? TILE_WALL : TILE_FLOOR;
		}
	}
}

const struct tile_data *map_at(struct map *m, int x, int y)
{
	assert(index_at(x, y) < MAP_TILES_LEN);

	tile_t tile = m->tiles[index_at(x, y)];
	return get_tile_data(tile);
}

void map_init(struct map *m, int dungeon_level)
{
	LOG_DEBUG("Generating dungeon level: %d", dungeon_level);

	memset(m, 0, sizeof(*m));
	mkroom(m, &(struct room_params){
		.x = 2,
		.y = 2,
		.width = 10,
		.height = 10
	});
}
