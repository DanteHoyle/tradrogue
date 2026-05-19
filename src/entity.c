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
	int dx, dy;
	vector_from_direction(dir, &dx, &dy);

	int next_x = e->x + dx;
	int next_y = e->y + dy;

	const struct tile_data *td = map_at(m, next_x, next_y);

	if (!td->solid)
		entity_move_to(e, next_x, next_y);
}
