#ifndef _TEXTUREMGR_H
#define _TEXTUREMGR_H

#include <map>
#include <SDL.h>
#include <stdio.h>
#include "texture.h"

class TextureManager
{
	private:

		std::map<char*, Texture*> textureList;


	public:

		bool Add(SDL_Renderer* renderer, char* id, char* filename);

		bool Remove(char* id);

		TextureManager();

		void Close();

		Texture* Get(char* id);
};

#endif