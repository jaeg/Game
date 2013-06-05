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

 //Data for the animation event
class CAnimationData
{
    CAnimationData(int start,int end)
    {
        startFrame=start;
        endFrame=end;
    }
    int startFrame;
    int endFrame;

};
//Data for a collision event.  Provides the two nodes that collided.
class CCollisionData
{
    CCollisionData(IAnimatedMeshSceneNode* tnode1,IAnimatedMeshSceneNode* tnode2)
    {
        node1=tnode1;
        node2=tnode2;
    }
    IAnimatedMeshSceneNode* node1;
    IAnimatedMeshSceneNode* node2;
};
class CSimpleCollisionData
{
    CSimpleCollisionData(int tid)
    {
        id=tid;
    }
    int id;
};
#endif
