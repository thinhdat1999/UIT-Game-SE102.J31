#pragma once
#include "Weapon.h"

class WeaponShield : public Weapon
{
public:
	WeaponShield()
	{
		animation = new Animation(WEAPON, 0);
		vx = vy = 0;
		type = SHIELD;
	}

	void Render(float cameraX = 0, float cameraY = 0)
	{
	/*	auto frameIndex = player->curAnimation->CurFrameIndex - 1;
		if (frameIndex != 0 && frameIndex != 1) return;*/
		float x, y;
		auto sprite = animation->GetSprite(0);
		sprite->_isFlipHorizontal = player->isReverse;
		if (player->stateName != SITTING)
		{
			x = player->posX;
			y = player->posY + 8;
		}
		else {
			x = player->posX;
			y = player->posY - 2;
		}
		x += (player->isReverse ? 9 : -9);
		screenX = x - cameraX;
		screenY = cameraY - y;
		sprite->Render(screenX, screenY);
	}
};