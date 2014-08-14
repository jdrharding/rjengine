#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "eventhandler.h"
#include <vector>
#include <memory>

class Observer {
public:
    //! Template function that also converts the event into the right data type before calling the event listener. 
    template<class T>
    bool OnEvent(std::function<void(std::shared_ptr<T>)> proc){
        return OnEvent(T::ID(), [&, proc](EventPtr data){
            auto ev = std::dynamic_pointer_cast<T>(data); 
            if(ev) proc(ev); 
        }); 
    }
protected:
    typedef std::pair<Event::id_t, EventDelegate> _EvPair; 
    Observer(std::weak_ptr<EventHandler> mgr):_els_mEventHandler(mgr){

    }
    virtual ~Observer(){
        if(_els_mEventHandler.expired()) return; 
        auto em = _els_mEventHandler.lock(); 
        for(auto i : _els_mLocalEvents){
            em->RemoveObserver(i.first, i.second); 
        }
    }

    bool OnEvent(Event::id_t id, EventDelegate proc){
        if(_els_mEventHandler.expired()) return false; 
        auto em = _els_mEventHandler.lock(); 
        if(em->AddObserver(id, proc)){
            _els_mLocalEvents.push_back(_EvPair(id, proc)); 
        }
    }
private:
    std::weak_ptr<EventHandler> _els_mEventHandler; 
    std::vector<_EvPair>        _els_mLocalEvents; 
    //std::vector<_DynEvPair> mDynamicLocalEvents; 
};

#endif