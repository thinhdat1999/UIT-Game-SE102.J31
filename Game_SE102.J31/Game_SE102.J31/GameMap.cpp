#include "GameMap.h"

GameMap::GameMap(const char* filePath)
{
	LoadMap(filePath);
}

GameMap::~GameMap()
{
}

void GameMap::LoadMap(const char* filePath)
{
	ifstream input;
	input.open(filePath);
	int numSetTiles;
	if (input.is_open())
	{
		input >> rows >> columns;
		mWidth = columns << 4;
		mHeight = rows << 4;
		rect.width = mWidth;
		rect.height = mHeight;
		rect.x = 0;
		rect.y = rect.height;



		mapMatrix = new int*[rows];
		for (int i = 0; i < rows; ++i)
		{
			mapMatrix[i] = new int[columns];
			for (int j = 0; j < columns; ++j)
			{
				input >> mapMatrix[i][j];
			}
		}
		input >> numSetTiles;
		auto sprites = SpriteManager::GetInstance();
		for (int i = 0; i < numSetTiles; ++i)
		{
			sprites->AddSprite(new CSprite(MAP1, i << 4, 0, i + 1 << 4, 16));
		}
	}

}


void GameMap::Render()
{
	auto sprites = SpriteManager::GetInstance();
	for (int i = 0; i != rows; ++i)
	{
		for (int j = cBegin; j != cEnd; ++j)
		{
			auto sprite = sprites->GetSprite(MAP1, mapMatrix[i][j]);
			sprite->Render((j << 4) + (16 >> 1) - (int)mCamera->x, ((i << 4) + (16 >> 1)));
		}
	}

}

int GameMap::getRow()
{
	return rows;
}

int GameMap::getColumn()
{
	return columns;
}

void GameMap::Update(float dt)
{
	mCamera->Update(this->rect);
	cBegin = max(0, mCamera->x / 16);
	cEnd = min(cBegin + ((mCamera->width >> 4) + 1), columns);
	/*rBegin = max(0, mCamera->y / 16);
	rEnd = min(rBegin + ((SCREEN_HEIGHT >> 4) + 1), rows);*/
}