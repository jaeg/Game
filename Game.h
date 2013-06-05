#pragma once
#include <irrlicht.h>
#include "Core\StateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Core/IEventHandler.h"
#include "Core/CEventDispatcher.h"
#include "InputListener.h"

using namespace irr;
class Game:public IEventHandler
{
public:
	Game(void);
	~Game(void);
	void Init();
	bool Run();
	void CleanUp();
	virtual void handleEvent(const Event& e);

private:
	StateMachine* stateMachine;
	IrrlichtDevice* device;
	InputListener* inputListener;
};

