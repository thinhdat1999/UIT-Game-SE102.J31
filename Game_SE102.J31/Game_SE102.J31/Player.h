#pragma once
#include "Object.h"
#include <unordered_set>
#include "PlayerState.h"
#include "PlayerStandingState.h"

class Player : public Object
{
private:
	unordered_map<State, Animation*> animations;		// Danh sách các Animation tương ứng với từng State
	static Player* _instance;

public:
	Player();
	~Player();

	static Player* GetInstance();

	PlayerState* state;
	State stateName;
	Animation* curAnimation;								// Animation hiện tại
	Type weaponType;
	unordered_map<State, bool> _allow;
	bool isThrowing, isAttacking;

	void Respawn();
	void ChangeState(PlayerState* newState);
	void Update(float dt);
	void Render(float cameraX = 0, float cameraY = 0);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};