#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Sprite
{
	public:
		Sprite();
		~Sprite();

		static SDL_Texture* Load(char* file, SDL_Renderer* renderer);

		static bool Draw(SDL_Renderer* renderer, SDL_Texture* texture, int xPos, int yPos);

		static bool Draw(SDL_Renderer* renderer, SDL_Texture* texture, int xPos, int yPos, int xBegin, int yBegin, int width, int height);
};

#endif