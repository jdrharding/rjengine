#ifndef _EVENT_H
#define _EVENT_H

#include <cstddef>
#include <memory>

class Event 
{
public:
	typedef size_t id_t;
	virtual id_t GetID() = 0;
};

typedef std::shared_ptr<Event> EventPtr;
typedef std::function<void(EventPtr&)> EventDelegate;

#define DECLARE_EVENT(type) \
    static Event::id_t ID(){ \
        return reinterpret_cast<Event::id_t>(&ID); \
    } \
    Event::id_t GetID() override { \
        return ID(); \
    }\

#endif