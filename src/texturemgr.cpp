#include "texturemgr.h"
#include "rjengine.h"

TextureManager::TextureManager()
{	
}

bool TextureManager::Add(SDL_Renderer* renderer, char* id, char* filename)
{
	Texture* newtexture = new Texture();
	if(!newtexture->Load(filename, renderer))
	{
		printf("TextureManager::Add - Unable to load texture!\n");
		return false;
	}
	textureList[id] = newtexture;
	return true;
}

bool TextureManager::Remove(char* id)
{
	if(textureList.find(id) == textureList.end())
	{
		return false;
	}

	Texture* texture = textureList[id];
	texture->Texture::~Texture();
	delete texture;
	texture = NULL;
}

Texture* TextureManager::Get(char* id)
{
	if (textureList.find(id) == textureList.end())
	{
		return 0;
	}

	return textureList[id];
}

void TextureManager::Close()
{
	if(textureList.size() <= 0) 
	{
		return;
	}
	else
	{
		for(auto& Iterator : textureList)
		{
			Texture* texture = (Texture*)Iterator.second;

			if(texture)
			{
				delete texture;
				texture = NULL;
			}
		}
	}
	textureList.clear();
}