#include "Object.h"

void Object::Update(float dt)
{
	dx = vx * dt;
	dy = vy * dt;
	posX += dx;
	posY += dy;
}
