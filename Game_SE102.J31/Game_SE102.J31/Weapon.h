#pragma once
#include "Player.h"
#include <unordered_set>
#include <map>

class Weapon : public Object
{
protected:
	Animation* animation;

public:
	Weapon()
	{
		tag = WEAPON;
		if (player->isThrowing)
		{
			player->_allow[THROWING] = false;
		}
	}

	~Weapon()
	{
		if (type != SHIELD)
		{
			player->_allow[THROWING] = true;
		}
	}

	/*virtual void Update(float dt) {};*/			// Update thông số của Object sau khoảng thời gian delta-time

	virtual void Render(float cameraX = 0, float cameraY = 0)
	{
		screenX = this->posX - cameraX;
		screenY = cameraY - this->posY;
		animation->isReverse = this->isReverse;
		animation->Render(screenX, screenY);
	}

	virtual void UpdateDistance(float dt)
	{
		this->dx = vx * dt;
		this->dy = vy * dt;
	}

	virtual void Update(float dt)
	{
		this->UpdateDistance(dt);
		if (player->isThrowing) {
			this->posX += dx;
			this->posY += dy;
		}
		else
		{
			this->posX = player->posX;
			this->posY = player->posY;
		}

		animation->isReverse = player->isReverse;
		animation->Update(dt);
	}
};