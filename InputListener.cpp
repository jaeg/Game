#include "InputListener.h"


InputListener::InputListener(void)
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
	inputMap.KeyIsDown[i] = false;
	inputMap.mouseX = 0;
	inputMap.mouseY = 0;
	inputMap.leftMouseButton = 0;
	inputMap.rightMouseButton = 0;
	inputMap.middleMouseButton = 0;
}


InputListener::~InputListener(void)
{
}

bool InputListener::OnEvent(const SEvent& event)
{
	if (event.EventType == EET_KEY_INPUT_EVENT)
	{
		inputMap.KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		Event inputEvent;
		inputEvent.category = EC_USERINPUT;
		inputEvent.type = E_KEYINPUT;
		inputEvent.data = &inputMap;

		CEventDispatcher::inst()->sendEvent(inputEvent);
	}

	if (event.EventType == EET_MOUSE_INPUT_EVENT)
	{
		inputMap.mouseX = event.MouseInput.X;
		inputMap.mouseY = event.MouseInput.Y;
		inputMap.leftMouseButton = event.MouseInput.isLeftPressed();
		inputMap.rightMouseButton = event.MouseInput.isRightPressed();
		inputMap.middleMouseButton = event.MouseInput.isMiddlePressed();

		Event inputEvent;
		inputEvent.category = EC_USERINPUT;
		inputEvent.type = E_MOUSEINPUT;
		inputEvent.data = &inputMap;

		CEventDispatcher::inst()->sendEvent(inputEvent);
	}
	return false;
}