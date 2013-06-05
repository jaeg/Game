#pragma once
#include <irrlicht.h>
#include "Core/CEventDispatcher.h"
#include "UserInput.h"
#include <iostream>

using namespace irr;
class InputListener :
	public IEventReceiver
{
public:
	InputListener(void);
	~InputListener(void);

	virtual bool OnEvent(const SEvent& event);
private:
	UserInput inputMap;
	
};

