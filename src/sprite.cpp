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
			//printf("%s, %d, %s\n", child->first_attribute("Name")->value(), index, child->first_attribute("Frames")->value());
			for (rapidxml::xml_node<> *gchild = child->first_node(); gchild; gchild = gchild->next_sibling())
			{
				std::map<int, SDL_Rect> ginner;
				SDL_Rect rect = {atoi(gchild->first_attribute("XPos")->value()), atoi(gchild->first_attribute("YPos")->value()), atoi(gchild->first_attribute("Height")->value()), atoi(gchild->first_attribute("Width")->value())};
				ginner.insert(std::make_pair(atoi(gchild->first_attribute("ID")->value()), rect));
				aFrames.insert(std::make_pair(index, ginner)); 
				//printf("%d, %s, %s, %s, %s, %s\n", index, gchild->first_attribute("ID")->value(), gchild->first_attribute("XPos")->value(), gchild->first_attribute("YPos")->value(), gchild->first_attribute("Height")->value(), gchild->first_attribute("Width")->value());
			}
			index++;
		}

	}
	return true;

	for(afIter it = aFrames.begin(); it != aFrames.end(); it++)
	{
		for(std::map<int, SDL_Rect>::iterator git = it->second.begin(); git != it->second.end(); git++)
		{
		std::cout << it->first << ", " << git->first << ", x:" << git->second.x << ", y:" << git->second.y << std::endl;
	}	}
}

void Sprite::Draw(std::string anim)
{
	int cframe = currFrame;
	if (currAnim != aList[anim].first)
	{
		currAnim = aList[anim].first;
		currFrame = 1;
	}
	else if (cframe + 1 > aList[anim].second)
	{
		currFrame = 1;
	}
	else
	{
		currFrame++;
	}

	SDL_Rect rect = aFrames[currAnim][currFrame];
	std::cout << "Drawing " << anim << ", ID: " << currAnim << ". Coords: x:" << rect.x << " y:" << rect.y << std::endl;
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