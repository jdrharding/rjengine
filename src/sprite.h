#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <map>
#include <utility>
#include "texturemgr.h"
#include "rapidxml.hpp"

class Sprite
{
	private:
		static char* id;
		int xPos;
		int yPos;
		int currFrame;
		int currAnim;

		static TextureManager* textureMgr;
		static std::map<char*, std::pair<int, int>> animationList;
		static std::map<int, std::map<int, SDL_Rect>> animationFrames;   
		
	public:
		Sprite(char* id, int x, int y);

		static bool Initialize(char* ifile, char* dfile, SDL_Renderer* renderer, TextureManager* texMgr);

		void Draw(char*);
		int GetX();
		int GetY();

};

#endif