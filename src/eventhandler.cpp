#include "eventhandler.h"
#include <iostream>

using namespace std; 

bool EventHandler::AddObserver(IEvent::id_t id, EventDelegate proc)
{
    auto i = Observers.find(id); 
    if(i == Observers.end()){
        Observers[id] = list<EventDelegate>(); 
    }
    auto &list = Observers[id]; 
    for(auto i = list.begin(); i != list.end(); i++){
        EventDelegate &func = *i; 
        if(func.target<EventDelegate>() == proc.target<EventDelegate>()) 
            return false; 
    }
    list.push_back(proc); 
}

bool EventHandler::RemoveObserver(IEvent::id_t id, EventDelegate proc)
{
    auto j = Observers.find(id); 
    if(j == Observers.end()) return false; 
    auto &list = j->second; 
    for(auto i = list.begin(); i != list.end(); ++i){
        EventDelegate &func = *i; 
        if(func.target<EventDelegate>() == proc.target<EventDelegate>()) {
            list.erase(i); 
            return true; 
        }
    }
    return false; 
}

void EventHandler::QueueEvent(EventPtr ev) {
    Events.push_back(ev); 
}

void EventHandler::Process(){
    std::size_t count = Events.size(); 
    for(auto iter = Events.begin(); iter != Events.end(); ++iter)
    {
        printf("Processing event..\n"); 
        if(!count) break; 
        auto &i = *iter; 
        auto obs = Observers.find(i->GetID()); 
        if(obs != Observers.end()){
            // Call listeners
            for(auto l : obs->second){
            	cout << "I should be doing something!" << endl;
                l(i); 
            }
        }
        // remove event
        iter = Events.erase(iter); 
        count--; 
    }
}