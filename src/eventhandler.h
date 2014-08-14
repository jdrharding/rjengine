#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H

#include "event.h"
#include <map>
#include <list>

class EventHandler
{

public:
    typedef std::list<EventDelegate> EventDelegateList; 

    ~EventHandler(){
    } 
    //! Adds a listener to the event. The listener should invalidate itself when it needs to be removed. 
    bool AddObserver(Event::id_t id, EventDelegate evnt); 

    //! Removes the specified delegate from the list
    bool RemoveObserver(Event::id_t id, EventDelegate evnt); 

    //! Queues an event to be processed during the next update
    void QueueEvent(EventPtr ev); 

    //! Processes all events
    void Process(); 

private:
    std::list<std::shared_ptr<Event>> Events; 
    std::map<Event::id_t, EventDelegateList> Observers; 

};

#endif