#include "vec2.h"

struct vec2 vec2_add(const struct vec2 *v1, const struct vec2 *v2)
{
	return (struct vec2){
		.x = v1->x + v2->x,
		.y = v1->y + v2->y
	};
}
