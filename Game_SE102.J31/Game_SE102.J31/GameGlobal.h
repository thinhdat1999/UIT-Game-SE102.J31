#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <WinUser.h>
#include <unordered_map>

#define SCREEN_WIDTH 720			// Chiều dài cửa sổ
#define SCREEN_HEIGHT 176			// Chiều cao cửa sổ
#define MAX_FRAME_RATE 120				// FPS
#define WIN_NAME "Captain America and The Avengers"
#define WIN_TITLE "Captain America and The Avengers"
#define KEYBOARD_BUFFER_SIZE 1024
#define DEFAULT_TPF 120
extern LPD3DXSPRITE spriteHandler; 
extern LPDIRECT3DDEVICE9 d3ddev;
extern LPDIRECT3DSURFACE9 backBuffer; // Back buffer
extern LPDIRECT3DSURFACE9 surface;
extern bool isGameRunning;
extern std::unordered_map<int, bool> keyCode;

#define mCamera Camera::GetInstance()
#define player Player::GetInstance()



// ===== Thông số Captain =====
#define PLAYER_RUNNING_SPEED 0.2f
// ====== ENUM của Object  ======
extern enum Tag
{
	PLAYER,
	CAPTAIN,
	ITEM,
	WEAPON,
	GROUND,
	MAP1,
	MAP2,
	MAP3,
	FONT,
	ENEMY,
	HOLDER,
	BULLET,
	MENUSCENE,
	CHANGESCENE,
	INTROSCENE,
	ENDSCENE,
};

// ====== Type Object ======
extern enum Type
{
	NONE,
	SHIELD,
	BOSS,
	EXPLODED,
};

extern enum State
{
	STANDING,
	RUNNING,
	DASHING,
	JUMPING,
	FALLING,
	SITTING,
	ATTACKING,
	ATTACKING_STAND,
	ATTACKING_SIT,
	THROWING,
	CLINGING,
	ACTIVE,
	DEAD,
	INJURED
};

struct Rect {
	float x, y;
	float width, height;
	Rect() {}
	Rect(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	bool isContain(Rect r)
	{
		return !((x + width < r.x) || (x > r.x + r.width) || (y < r.y - r.height) || (y - height > r.y));
	}
};