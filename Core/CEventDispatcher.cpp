#include "CEventDispatcher.h"
#include "IEventHandler.h"

CEventDispatcher* CEventDispatcher::pInstance=0;

CEventDispatcher::CEventDispatcher()
{
    //ctor
}

CEventDispatcher::~CEventDispatcher()
{
    //dtor
}

CEventDispatcher* CEventDispatcher::inst()
{
    if (pInstance == 0)
    {
        pInstance = new CEventDispatcher;
    }
    return pInstance;
}

void CEventDispatcher::addHandler(IEventHandler* handler, EventCategory category)
{
	handlerMap[category].push_back(handler);
}

void CEventDispatcher::sendEvent(Event& event)
{
	vector<IEventHandler*> *handlerList = &handlerMap[event.category];
	for (unsigned int i=0;i<handlerList->size();i++)
    {
		handlerList->at(i)->handleEvent(event);
    }

}

bool CEventDispatcher::removeHandler(IEventHandler* handler,EventCategory category)
{
	vector<IEventHandler*> *handlerList = &handlerMap[category];

	for (unsigned int i=0;i<handlerList->size();i++)
    {
		if (handlerList->at(i) == handler)
		{
			handlerList->erase(handlerList->begin()+i);
			return true;
		}
    }

    return false;

}

void CEventDispatcher::clear()
{
    
}
