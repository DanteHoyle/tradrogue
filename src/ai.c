#include "ai.h"

#include <assert.h>
#include "random.h"

void ai_next_action(struct entity *e)
{
	assert(e != nullptr);
	assert(e->type == ENTITY_MONSTER);
	// TODO: Add real AI behavior
	e->x += random_int(-1, 1);
	e->y += random_int(-1, 1);
}
