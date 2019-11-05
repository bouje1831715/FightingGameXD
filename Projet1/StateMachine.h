#pragma once
#include "EntityState.h"

namespace GameView
{

	class StateMachine
	{

	public:
		StateMachine();
		~StateMachine();
		void changeState(EntityFiniteState newState);

	private:
		EntityState* getNewState(EntityFiniteState newState);
		

		EntityState* currentState;
	};

}
