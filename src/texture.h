#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>

class Texture
{
	private:
		
		SDL_Renderer* renderer = NULL;
		SDL_Texture* texture = NULL;

		int width = 0;
		int height = 0;

	public:

		Texture();
		~Texture();

		bool Load(char* file, SDL_Renderer* renderer);

		void Draw(int xPos, int yPos);

		void Draw(int xPos, int yPos, int xBegin, int yBegin, int width, int height);

};

#endif