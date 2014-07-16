#ifndef _TEXTUREMGR_H
#define _TEXTUREMGR_H

#include <vector>
#include <map>
#include <SDL.h>
#include "texture.h"

class TextureManager
{
	private:

		static std::map<char*, SDL_Texture *> textureList;

		static bool Add(SDL_Renderer* renderer, char* id, char* file);

	public:

		static bool Initialize();

		static void Close();

		static Texture Get(char* id);

		static TextureManager* Instance();
};

#endif