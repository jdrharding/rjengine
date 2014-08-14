#include "observer.h"
#include "sprite.h"

class TransportEvent : public Event
{
private:

	int mXPos;
	int mYPos;
	Sprite* spr;

public:

	DECLARE_EVENT(TransportEvent);

	TransportEvent(int xpos, int ypos, Sprite* spr)
	{
		mXPos = xpos;
		mYPos = ypos;
	}

	void TransportSprite()
	{
		spr->ChangeXPos(mXPos);
		spr->ChangeYPos(mYPos);
	}
};