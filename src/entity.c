#include "entity.h"
#include "util.h"

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

void entity_move_dir(struct entity *e, enum DIRECTION dir)
{
	switch (dir) {
        case DIR_N:
		entity_move_by(e, 0, -1);
		return;
        case DIR_S:
		entity_move_by(e, 0, 1);
		return;
        case DIR_W:
		entity_move_by(e, -1, 0);
		return;
        case DIR_E:
		entity_move_by(e, 1, 0);
		return;
        case DIR_NW:
		entity_move_by(e, -1, -1);
		return;
        case DIR_NE:
		entity_move_by(e, 1, -1);
		return;
        case DIR_SW:
		entity_move_by(e, -1, 1);
		return;
        case DIR_SE:
		entity_move_by(e, 1, 1);
		return;
        }
}
