#ifndef IEVENTHANDLER_H
#define IEVENTHANDLER_H

#include "Event.h"
#include "CEventDispatcher.h"


class IEventHandler {

public:
  virtual void handleEvent(const Event& e)=0;

  IEventHandler()
  {
  }
};

#endif // IEVENTHANDLER_H
