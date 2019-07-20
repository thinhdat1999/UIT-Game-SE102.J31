#include "TextureManager.h"
TextureManager * TextureManager::_instance = NULL;
void TextureManager::StartUp()
{
	TextureManager * textures = TextureManager::GetInstance();
	textures->AddTexture(PLAYER, "Captain.png", D3DCOLOR_XRGB(0, 166, 81));
	textures->AddTexture(MAP1, "Resource/CharlestonTiles.png", D3DCOLOR_XRGB(0, 0, 0));
}

void TextureManager::AddTexture(Tag tag, LPCSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	LPDIRECT3DTEXTURE9 texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddev,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);

	textures[tag] = texture;
}

LPDIRECT3DTEXTURE9 TextureManager::GetTexture(Tag tag)
{
	return textures[tag];
}

TextureManager * TextureManager::GetInstance()
{
	if (_instance == NULL) _instance = new TextureManager();
	return _instance;
}