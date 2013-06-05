#include <iostream>
#include "Game.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")

#endif

int main()
{
	Game game;

	game.Init();
	
	while (game.Run());

	game.CleanUp();
	return 0;
}