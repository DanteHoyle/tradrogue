#include "tile.h"

#include <assert.h>

static struct tile_data tile_table[] = {
	[TILE_EMPTY]	= {.name="Empty", .solid = false, .rune=' '},
	[TILE_FLOOR]	= {.name="Floor", .solid=false, .rune='.'},
	[TILE_WALL]	= {.name="Wall", .solid=true, .rune='#'},
	[TILE_DOOR]	= {.name="Closed Door", .solid=false, .rune='.'},
};

// Compile time check that the enum count matches the size of tile_table
// This protects against accidentally adding a row to tile_table without a 
// corresponding enum or vice versa.
static_assert(sizeof(tile_table)/sizeof(tile_table[0]) == TILE_COUNT,
	      "tile_table size doesn't match TILE_COUNT");

const struct tile_data *get_tile_data(tile_t type)
{
	assert(type >= 0 && type < TILE_COUNT);
	return &tile_table[type];
}
