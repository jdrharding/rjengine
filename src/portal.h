#include "eventhandler.h"
#include "transportevent.h"
#include "sprite.h"
#include <cmath>
#include <iostream>

class Portal 
{
private:
	std::shared_ptr<EventHandler> eHandler;
	int mXPos;
	int mYPos;	

public:
	Portal(std::shared_ptr<EventHandler> eh, int xpos, int ypos)
	{
		eHandler = eh;
		mXPos = xpos;
		mYPos = ypos;

		OnEvent<TransportEvent>([&] std::shared_ptr<TransportEvent> data)
		{
			
		}
	}

	void ActivatePortal(Sprite* spr) 
	{
		eHandler->QueueEvent(std::shared_ptr<IEvent>(new TransportEvent(60, 60, spr)));
	}

	void CheckProximity(Sprite* spr)
	{
		if (sqrt(pow(spr->GetX() - mXPos, 2) + pow(spr->GetY() - mYPos, 2)) <= 5)
		{
			ActivatePortal(spr);
		}
	}
};