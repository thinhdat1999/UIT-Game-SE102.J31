#include "SpriteManager.h"

SpriteManager * SpriteManager::_instance = NULL;

SpriteManager *SpriteManager::GetInstance()
{
	if (_instance == NULL) _instance = new SpriteManager();
	return _instance;
}

void SpriteManager::StartUp()
{
	auto sprites = SpriteManager::GetInstance();
	//Load Sprites
	sprites->AddSprite(new PlayerSprite(STANDING, 20, 10, 43, 58));
	sprites->AddSprite(new PlayerSprite(RUNNING, 52, 10, 77, 58));
	sprites->AddSprite(new PlayerSprite(RUNNING, 84, 10, 109, 58));
	sprites->AddSprite(new PlayerSprite(SITTING, 211, 27, 236, 57));


	//Load Weapon
	sprites->AddSprite(new WeaponSprite(SHIELD, 99, 271, 108, 289));
	sprites->AddSprite(new WeaponSprite(SHIELD, 115, 271, 132, 289));
	sprites->AddSprite(new WeaponSprite(SHIELD, 140, 271, 157, 289));
	sprites->AddSprite(new WeaponSprite(SHIELD, 164, 279, 189, 289));
}


CSprite* SpriteManager::GetSprite(Tag tag, int index)
{
	return _sprites[tag][index];
}

// Lấy các Sprite (dùng cho tạo Animation) theo Tag từ vị trí first->last
std::vector<CSprite*> SpriteManager::GetSprites(Tag tag, int firstIndex, int lastIndex)
{
	auto first = _sprites[tag].begin() + firstIndex;
	auto last = _sprites[tag].begin() + lastIndex;
	return std::vector<CSprite*>(first, last + 1);
}

void SpriteManager::AddSprite(CSprite* sprite)
{
	_sprites[sprite->tag].push_back(sprite);
}
