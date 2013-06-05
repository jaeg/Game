#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::handleEvent(const Event& e)
{
	if (e.type == E_PLAYSTATE)
	{
		stateMachine->SwitchState(new PlayState(device));
	}
	else if (e.type == E_MAINMENUSTATE)
	{
		stateMachine->SwitchState(new MenuState(device));
	}
	else if (e.type == E_CLOSE)
	{
		device->closeDevice();
	}
	else if (e.type == E_KEYINPUT)
	{
		cout<<"Keyboard input\n";
	}
	else if (e.type == E_MOUSEINPUT)
	{
		cout<<"Mouse input\n";
	}
}

void Game::Init()
{
	CEventDispatcher::inst()->addHandler(this,EC_GAME);
	CEventDispatcher::inst()->addHandler(this,EC_USERINPUT);
	inputListener = new InputListener();
	device =
		createDevice( video::EDT_OPENGL, core::dimension2d<u32>(640, 480), 16,
			false, false, false, inputListener);


	stateMachine = new StateMachine();
	stateMachine->SwitchState(new MenuState(device));
}



void Game::CleanUp()
{
	CEventDispatcher::inst()->removeHandler(this,EC_GAME);
	CEventDispatcher::inst()->removeHandler(this,EC_USERINPUT);
	stateMachine->CleanUp();
	stateMachine->Drop();
	device->drop();
}

bool Game::Run()
{
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	if(device->run())
	{
		stateMachine->Update();
		driver->beginScene(true, true, video::SColor(255,100,101,140));
		stateMachine->Draw();
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
	

	return true;
}