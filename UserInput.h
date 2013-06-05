#include <irrlicht.h>

using namespace irr;
struct UserInput
{
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	int mouseX;
	int mouseY;
	bool leftMouseButton;
	bool rightMouseButton;
	bool middleMouseButton;
};