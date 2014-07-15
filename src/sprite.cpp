#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

SDL_Texture* Sprite::Load(char *file, SDL_Renderer* renderer)
{
	SDL_Texture* texture;
	SDL_Surface* surface;

	if ((surface = IMG_Load(file)) == NULL)
	{
		printf("Unable to load %s! SDL_Image Error: %s\n", file, IMG_GetError() );
		return NULL;
	}
	else
	{
		if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
		{
			printf("Unable to create texture from file %s! SDL Error: %s\n", file, SDL_GetError());
		}
	}

	SDL_FreeSurface(surface);

	return texture;
}

bool Sprite::Draw(SDL_Renderer* renderer, SDL_Texture* texture, int xPos, int yPos)
{
	SDL_Rect rectTo;

	rectTo.x = xPos;
	rectTo.y = yPos;

	SDL_RenderCopy(renderer, texture, NULL, &rectTo);

	return true;
}

bool Sprite::Draw(SDL_Renderer* renderer, SDL_Texture* texture, int xPos, int yPos, int xBegin, int yBegin, int width, int height)
{
	SDL_Rect rectFrom, rectTo;

	rectTo.x = xPos;
	rectTo.y = yPos;

	rectFrom.x = xBegin;
	rectFrom.y = yBegin;
	rectFrom.w = width;
	rectFrom.h = height;

	SDL_RenderCopy(renderer, texture, &rectFrom, &rectTo);

	return true;
}