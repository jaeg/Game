#include "PlayState.h"

#include <iostream>
PlayState::PlayState(IrrlichtDevice* tDevice)
{
	device = tDevice;
}


PlayState::~PlayState(void)
{
	cout<<"Play state destroyed\n";
}

void PlayState::CleanUp()
{
	std::cout<<"Play state cleaned up\n";
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
    guienv->clear();
}

void PlayState::Draw()
{

}

void PlayState::Init()
{
	std::cout<<"Play state initialized\n";
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	guienv->addStaticText(L"Raptor Engine - Play State",
	core::rect<s32>(10,10,260,22), true);
	menuButton = guienv->addButton(core::rect<s32>(350,250,450,320),0,-1,L"Menu",L"Select to play game");
	exitButton = guienv->addButton(core::rect<s32>(350,325,450,400),0,-1,L"Exit",L"Select to exit game");
}

void PlayState::Update()
{
		if (menuButton->isPressed())
	{
		std::cout<<"Play has been clicked!\n";
		Event playEvent;
		playEvent.category = EC_GAME;
		playEvent.type = E_MAINMENUSTATE;
		playEvent.data = 0;
		CEventDispatcher::inst()->sendEvent(playEvent);
		return;
	}
	
	if (exitButton->isPressed())
	{
		std::cout<<"Exit has been clicked!\n";
		Event playEvent;
		playEvent.category = EC_GAME;
		playEvent.type = E_CLOSE;
		playEvent.data = 0;
		CEventDispatcher::inst()->sendEvent(playEvent);
		return;
	}
}