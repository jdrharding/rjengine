#ifndef _EVENT_H
#define _EVENT_H

#include <cstddef>

class Event 
{
public:
	typedef size_t id_t;
	virtual id GetID() = 0;
};

typedef std::shared_ptr<Event> EventPtr;
typedef std::function<void(EventPtr&)> EventDelegate;

#endif