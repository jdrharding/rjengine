#ifndef _EVENT_H
#define _EVENT_H

#include <cstddef>
#include <memory>

class IEvent 
{
public:
	typedef size_t id_t;
	virtual id_t GetID() = 0;
};

typedef std::shared_ptr<IEvent> EventPtr;
typedef std::function<void(EventPtr&)> EventDelegate;

#define DECLARE_EVENT(type) \
    static IEvent::id_t ID(){ \
        return reinterpret_cast<IEvent::id_t>(&ID); \
    } \
    IEvent::id_t GetID() override { \
        return ID(); \
    }\

#endif