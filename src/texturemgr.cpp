#include "texturemgr.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

void TextureManager::Add(SDL_Texture* text)
{
	textureList.push_back(text);
}

SDL_Texture* TextureManager::Get(int index)
{
	return textureList[index];
}