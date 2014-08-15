#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include "texturemgr.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "eventhandler.h"
#include "observer.h"

class Sprite : public Observer
{
	private:
		char* id;
		int xPos;
		int yPos;
		int currFrame;
		int currAnim;

		int lastUpdate = 0;
		int currentTime;
		int updateTime = 100;

		std::string nextAnim;

		typedef std::map<std::string, std::pair<int, int>> animationList;
		typedef animationList::iterator alItr;
		typedef std::map<int, std::map<int, SDL_Rect>> animationFrames; 
		typedef animationFrames::iterator afIter;

		animationList aList;
		animationFrames aFrames;
		TextureManager* textureMgr;
		
	public:
		Sprite(char* id, int x, int y);

		bool Initialize(char* ifile, char* dfile, SDL_Renderer* renderer, TextureManager* texMgr);

		void Draw();
		void SetNextAnim(std::string newAnim);
		void SetXPos(int newX);
		void SetYPos(int newY);
		void ChangeXPos(int newX);
		void ChangeYPos(int newY);
		int GetX();
		int GetY();
};

#endif