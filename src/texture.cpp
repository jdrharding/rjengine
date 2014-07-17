#include "texture.h"
#include <stdio.h>

Texture::Texture()
{

}

Texture::~Texture()
{
	if(texture)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}

bool Texture::Load(char *file, SDL_Renderer* renderer)
{
	if(renderer == NULL)
	{
		return false;
	}

	this->renderer = renderer;

	SDL_Surface* surface;

	if ((surface = IMG_Load(file)) == NULL)
	{
		printf("Unable to load %s! SDL_Image Error: %s\n", file, IMG_GetError() );
		return false;
	}
	else
	{
		if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
		{
			printf("Unable to create texture from file %s! SDL Error: %s\n", file, SDL_GetError());
			return false;
		}
	}

	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	return true;
}

void Texture::Draw(int xPos, int yPos)
{
	SDL_Rect rectTo;

	rectTo.x = xPos;
	rectTo.y = yPos;
	rectTo.h = height;
	rectTo.w = width;

	SDL_RenderCopy(renderer, texture, NULL, &rectTo);

}

void Texture::Draw(int xPos, int yPos, int xBegin, int yBegin, int width, int height)
{
	SDL_Rect rectFrom, rectTo;

	rectTo.x = xPos;
	rectTo.y = yPos;
	rectTo.w = width;
	rectTo.h = height;

	rectFrom.x = xBegin;
	rectFrom.y = yBegin;
	rectFrom.w = width;
	rectFrom.h = height;

	SDL_RenderCopy(renderer, texture, &rectFrom, &rectTo);

}