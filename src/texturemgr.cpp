#include "texturemgr.h"
#include "rjengine.h"

bool TextureManager::Initialize()
{
	Close();

	SDL_Renderer* renderer = RJEngine::
}

void TextureManager::Add(SDL_Texture* text)
{

}

Texture* TextureManager::Get(char* id)
{
	if (textureList.find(id) == textureList.end())
	{
		return 0;
	}

	return textureList[id];
}