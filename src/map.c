#include "map.h"

#include "tile.h"
#include "log.h"
#include <assert.h>
#include <string.h>

struct room_params { int x, y, width, height; };

static inline int index_at(int x, int y) { return (y * MAP_WIDTH) + x; }

// Create a room on the map
static void mkroom(struct map *m, struct room_params r)
{
	for (int row = 0; row < r.width; row++) {
		for (int col = 0; col < r.height; col++) {
			bool is_wall = row == 0 || col == 0 || row == r.height - 1 || col == r.width - 1;
			m->tiles[index_at(r.x + col, r.y + row)] = is_wall ? TILE_WALL : TILE_FLOOR;
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
	m->dungeon_level = dungeon_level;
	mkroom(m, (struct room_params){
		.x = 2,
		.y = 2,
		.width = 10,
		.height = 10
	});
}
