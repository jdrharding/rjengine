#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "eventhandler.h"
#include <vector>
#include <memory>

class Observer {

public:
    template<class T>
    bool OnEvent(std::function<void(std::shared_ptr<T>)> proc){
        return OnEvent(T::ID(), [&, proc](EventPtr data){
            //convert the shared ptr to our event pointer
            auto ev = std::dynamic_pointer_cast<T>(data);
            //check if nullptr, if not null return our proc
            if(ev) proc(ev); 
        }); 
    }

protected:
    typedef std::pair<IEvent::id_t, EventDelegate> EPair; 
    Observer(std::weak_ptr<EventHandler> mgr):_els_mEventHandler(mgr){

    }
    virtual ~Observer(){
        if(_els_mEventHandler.expired()) return; 
        auto em = _els_mEventHandler.lock(); 
        for(auto i : _els_mLocalEvents){
            em->RemoveObserver(i.first, i.second); 
        }
    }

    bool OnEvent(IEvent::id_t id, EventDelegate proc){
        if(_els_mEventHandler.expired()) return false; 
        auto em = _els_mEventHandler.lock(); 
        if(em->AddObserver(id, proc)){
            _els_mLocalEvents.push_back(EPair(id, proc)); 
        }
    }
private:
    std::weak_ptr<EventHandler> _els_mEventHandler; 
    std::vector<EPair>        _els_mLocalEvents;
};

#endif