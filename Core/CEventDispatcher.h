#ifndef CEVENTDISPATCHER_H
#define CEVENTDISPATCHER_H
/*
The event dispatcher is the global communication system of the engine

Event type = type of event
Event Category = decides which handler gets the message
event data = pointer to data object that contains required information for handler to process request
*/

#include <vector>
#include <map>

#include "Event.h"
//#include "IEventHandler.h"

using namespace std;

class IEventHandler;

class CEventDispatcher
{
    public:
        virtual ~CEventDispatcher();

        static CEventDispatcher* inst();

        // Adds an event handler to the vector list
        void addHandler(IEventHandler* handler,EventCategory category);

        // Sends an event to all of the event handlers
        void sendEvent(Event& event);

        //Handler Removing Functions
        void clear();
        bool removeHandler(IEventHandler*,EventCategory category);

    protected:
        CEventDispatcher();
    private:
        static CEventDispatcher* pInstance;
		std::map<EventCategory,vector<IEventHandler*>> handlerMap;
};


#endif // CEVENTDISPATCHER_H
