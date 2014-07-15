#ifndef _TEXTUREMGR_H
#define _TEXTUREMGR_H

#include <vector>
#include <map>
#include <SDL.h>

class TextureManager
{
	private:

		std::map<char*, SDL_Texture *> textureList;
public:
	TextureManager();
	~TextureManager();

	void Add(SDL_Texture text);
	SDL_Texture Get(int index);
};

#endif