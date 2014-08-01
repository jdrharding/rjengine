#include "sprite.h"

std::map<char*, std::pair<int, int>> Sprite::animationList;
std::map<int, std::map<int, SDL_Rect>> Sprite::animationFrames;
char* id = "";
TextureManager* textureMgr = 0;

Sprite::Sprite(char* id, int x, int y)
{
	this->id = id;
	xPos = x;
	yPos = y;
	currFrame = 0;
	currAnim = 0;
}

bool Sprite::Initialize(char* ifile, char* dfile, SDL_Renderer* renderer, TextureManager* texMgr)
{
	textureMgr = texMgr;
	if(textureMgr->Add(renderer, id, ifile))
	{
		rapidxml::xml_document<> doc;
		doc.parse<0>(dfile);
		rapidxml::xml_node<> *node = doc.first_node("Sprite");
		int index = 0;
		
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
		{
			animationList.insert(std::make_pair(child->first_attribute("Name")->value(), std::make_pair(index,atoi(child->first_attribute("Frames")->value()))));
			
			for (rapidxml::xml_node<> *gchild = child->first_node(); gchild; gchild = gchild->next_sibling())
			{
				std::map<int, SDL_Rect> ginner;
				SDL_Rect rect = {atoi(gchild->first_attribute("XPos")->value()), atoi(gchild->first_attribute("YPos")->value()), atoi(gchild->first_attribute("Height")->value()), atoi(gchild->first_attribute("Width")->value())};
				ginner.insert(std::make_pair(atoi(gchild->first_attribute("ID")->value()), rect));
				animationFrames.insert(std::make_pair(index, ginner)); 
			}

		}

	}
	return true;
}

void Sprite::Draw(char* anim)
{
	int cframe = currFrame;
	if (currAnim != animationList[anim].first)
	{
		currAnim = animationList[anim].first;
		currFrame = 0;
	}
	else if (cframe + 1 > animationList[anim].second)
	{
		currFrame = 0;
	}
	else
	{
		currFrame++;
	}

	SDL_Rect rect = animationFrames[currAnim][currFrame];
	this->textureMgr->Get(id)->Draw(xPos, yPos, rect.x, rect.y, rect.h, rect.w);
}

int Sprite::GetX()
{
	return xPos;
}

int Sprite::GetY()
{
	return yPos;
}