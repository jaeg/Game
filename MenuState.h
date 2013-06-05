#pragma once
#include "Core/State.h"
#include "Core/CEventDispatcher.h"
#include <irrlicht.h>

using namespace irr;
class MenuState :
	public State
{
public:
	MenuState(IrrlichtDevice* tDevice);
	virtual ~MenuState(void);
	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void CleanUp();
private:
	IrrlichtDevice* device;
	gui::IGUIButton* playButton;
	gui::IGUIButton* exitButton;
};

