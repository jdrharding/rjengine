#include "sprite.h"

Sprite::Sprite(char* id, int x, int y)
{
	this->id = id;
	xPos = x;
	yPos = y;
	currFrame = 1;
	currAnim = 2;
}

bool Sprite::Initialize(char* ifile, char* dfile, SDL_Renderer* renderer, TextureManager* texMgr)
{
	textureMgr = texMgr;
	if(textureMgr->Add(renderer, id, ifile))
	{
		rapidxml::file<> file(dfile);
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());
		rapidxml::xml_node<> *node = doc.first_node("Sprite");
		int index = 0;
		
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
		{			
			aList.insert(std::make_pair(child->first_attribute("Name")->value(), std::make_pair(index, atoi(child->first_attribute("Frames")->value()))));
			std::map<int, SDL_Rect> ginner;
			for (rapidxml::xml_node<> *gchild = child->first_node(); gchild; gchild = gchild->next_sibling())
			{
				SDL_Rect rect = {atoi(gchild->first_attribute("XPos")->value()), atoi(gchild->first_attribute("YPos")->value()), atoi(gchild->first_attribute("Height")->value()), atoi(gchild->first_attribute("Width")->value())};
				ginner.insert(std::make_pair(atoi(gchild->first_attribute("ID")->value()), rect));
			}
			aFrames.insert(std::make_pair(index, ginner));
			ginner.clear();
			index++;
		}

	}
	return true;

	for(afIter it = aFrames.begin(); it != aFrames.end(); it++)
	{
		std::cout << it->first << std::endl;
		for(std::map<int, SDL_Rect>::iterator git = it->second.begin(); git != it->second.end(); git++)
		{
			std::cout << it->first << ", " << git->first << ", x:" << git->second.x << ", y:" << git->second.y << std::endl;
		}	
	}
}

void Sprite::Draw()
{
	currentTime = SDL_GetTicks();

	if((currentTime - lastUpdate) < updateTime)
	{
		SDL_Rect rect = aFrames[currAnim][currFrame];
		this->textureMgr->Get(id)->Draw(xPos, yPos, rect.x, rect.y, rect.h, rect.w);
		return;
	}

	lastUpdate = currentTime;

	if(nextAnim == "Idle")
	{
		SDL_Rect rect = aFrames[currAnim][1];
		this->textureMgr->Get(id)->Draw(xPos, yPos, rect.x, rect.y, rect.h, rect.w);
		return;
	}
	else if(nextAnim == "WalkLeft")
	{
		this->ChangeXPos(-5);
	}
	else if(nextAnim == "WalkRight")
	{
		this->ChangeXPos(5);
	}
	else if(nextAnim == "WalkUp")
	{
		this->ChangeYPos(-5);
	}
	else if(nextAnim == "WalkDown")
	{
		this->ChangeYPos(5);
	}

	int cframe = currFrame;
	if (currAnim != aList[nextAnim].first)
	{
		currAnim = aList[nextAnim].first;
		currFrame = 1;
	}
	else if (cframe + 1 > aList[nextAnim].second)
	{
		currFrame = 1;
	}
	else
	{
		currFrame++;
	}

	SDL_Rect rect = aFrames[currAnim][currFrame];
	this->textureMgr->Get(id)->Draw(xPos, yPos, rect.x, rect.y, rect.h, rect.w);
	nextAnim = "Idle";
}

void Sprite::SetNextAnim(std::string newAnim)
{
	nextAnim = newAnim;
}

int Sprite::GetX()
{
	return xPos;
}

int Sprite::GetY()
{
	return yPos;
}

void Sprite::SetXPos(int newX)
{
	xPos = newX;
}

void Sprite::SetYPos(int newY)
{
	yPos = newY;
}

void Sprite::ChangeXPos(int newX)
{
	xPos += newX;
}

void Sprite::ChangeYPos(int newY)
{
	yPos += newY;
}