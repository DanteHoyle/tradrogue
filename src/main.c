#include "ai.h"
#include "log.h"

#include "entity.h"

int main(void)
{
	struct entity m;
	entity_init_monster(&m, 0, 0, 2);

	for (int i = 0; i < 10; i++) {
		LOG_INFO("(x: %d, y: %d)", m.x, m.y);
		ai_next_action(&m);
	}
}
