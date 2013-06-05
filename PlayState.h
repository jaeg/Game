#pragma once
#include "core/State.h"
#include "Core/CEventDispatcher.h"
#include <irrlicht.h>

class PlayState :
	public State
{
public:
	PlayState(IrrlichtDevice* tDevice);
	virtual ~PlayState(void);
	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void CleanUp();
private:
	IrrlichtDevice* device;
	gui::IGUIButton* menuButton;
	gui::IGUIButton* exitButton;
};

