#include "StateMachine.h"


StateMachine::StateMachine()
{
    
}


void StateMachine::SwitchState(State* state)
{
    if (currentState != 0)
    {
		currentState->CleanUp();
		currentState->Drop();
    }
    
    currentState = state;
	currentState->Add();
	currentState->Init();
}

void StateMachine::SuspendSwitchState(State* state)
{
    if (currentState != 0)
    {
        pausedState = currentState;
    }
    currentState = state;
	currentState->Add();
	currentState->Init();

}

void StateMachine::RevertState()
{
    if (pausedState != 0)
    {
		currentState->CleanUp();
		currentState->Drop();
        currentState = pausedState;
        pausedState = 0;
    }
}

void StateMachine::Initialize()
{
    currentState = 0;
    pausedState = 0;
}

void StateMachine::Update()
{
    if (currentState != 0)
    {
        currentState->Update();
    }
}

void StateMachine::Draw()
{
     if (currentState != 0)
    {
        currentState->Draw();
    }   
}

void StateMachine::CleanUp()
{
    if (currentState != 0)
    {
        currentState->CleanUp();
		currentState->Drop();
    }
    
    if (pausedState != 0)
    {
        pausedState->CleanUp();
		pausedState->Drop();
    }
}