#include "entity.h"

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
