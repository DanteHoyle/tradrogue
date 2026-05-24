#include "entity.h"
#include "util.h"
#include "map.h"

void entity_move_by(struct entity *e, int dx, int dy)
{
	e->x += dx;
	e->y += dy;
}

void entity_move_to(struct entity *e, int x, int y)
{
	e->x = x;
	e->y = y;
}

void entity_move_dir(struct map *m, struct entity *e, enum direction dir)
{
	const struct vec2 *d = dir_to_vec2(dir);

	int next_x = e->x + d->x;
	int next_y = e->y + d->y;

	const struct tile_data *td = map_at(m, next_x, next_y);

	if (!td->solid)
		entity_move_to(e, next_x, next_y);
}
