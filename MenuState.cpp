#include "MenuState.h"

#include <iostream>

MenuState::MenuState(IrrlichtDevice* tdevice)
{
	device = tdevice;
}


MenuState::~MenuState(void)
{
	std::cout<<"Menu Destroyed\n";
}

void MenuState::CleanUp()
{
	std::cout<<"Menu state cleaned up\n";
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
    guienv->clear();

}

void MenuState::Draw()
{

}

void MenuState::Init()
{
	std::cout<<"Menu state initialized\n";
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	guienv->addStaticText(L"Raptor Engine",
		core::rect<s32>(10,10,260,22), true);
	playButton = guienv->addButton(core::rect<s32>(350,250,450,320),0,-1,L"Play",L"Select to play game");
	exitButton = guienv->addButton(core::rect<s32>(350,325,450,400),0,-1,L"Exit",L"Select to exit game");
}

void MenuState::Update()
{
	if (playButton->isPressed())
	{
		std::cout<<"Play has been clicked!\n";
		Event playEvent;
		playEvent.category = EC_GAME;
		playEvent.type = E_PLAYSTATE;
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