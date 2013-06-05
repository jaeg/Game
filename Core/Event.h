#ifndef CEVENT_H
#define CEVENT_H
#include <irrlicht.h>
using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
enum EventCategory
{
    EC_GAME,
	EC_USERINPUT
};

enum EventType
 {
   // Mouse button events. Each of the next six events gets passed
   // the absolute position of the mouse
   E_MOUSEINPUT,

   //Keyboard input
   E_KEYINPUT,

   // Start new games
   E_NEWGAMEEASY,
   E_NEWGAMENORMAL,
   E_NEWGAMEHARD,

   // Game play related
   E_INCREMENTSCORE,
   E_PAUSEGAME,
   E_CONTINUEGAME,
   E_GAMEOVER,

   //Game State Related
   E_MAINMENUSTATE,
   E_PLAYSTATE,
   E_CREDITSSTATE,

   // Close the App
   E_CLOSE,

   //Game related event
   E_COLLISIONOCCURED,
   E_ANIMATE
 };

 struct Event
 {
   EventType type;
   EventCategory category;
   void* data;
 };

 
#endif
