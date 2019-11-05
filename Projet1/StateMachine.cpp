#include "StateMachine.h"

namespace GameView
{

	StateMachine::StateMachine()
	{
	}

	StateMachine::~StateMachine()
	{
		if (currentState != nullptr)
			delete currentState;
	}

	void StateMachine::changeState(EntityFiniteState newState)
	{
		currentState->onExit();
		delete currentState;
		currentState = getNewState(newState);
	}

	EntityState* StateMachine::getNewState(EntityFiniteState newState)
	{
		EntityState* state = nullptr;
		switch( newState )
		{ 
			case EntityFiniteState::State_Idle: state = new StateIdle();
			break;
		}
		return state;
	}
}