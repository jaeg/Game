#pragma once
#include "State.h"
#include "StateEnum.h"
#include "Referenced.h"
class StateMachine : public Referenced
{
    private:
        State* currentState;
        State* pausedState;
    public:
        StateMachine();
 	void SwitchState(State* state); 
	void SuspendSwitchState(State* state); 
	void RevertState(); 
	void Initialize(); 
        void Update();
        void Draw(); 
	void CleanUp();
};