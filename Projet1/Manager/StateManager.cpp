#include "StateManager.h"

namespace GameView
{

	StateManager::StateManager()
	{
	}


	StateManager::~StateManager()
	{
	}


	void StateManager::addState( stateRef newState, bool isReplacing )
	{
		isAdding = true;
		this->isReplacing = isReplacing;

		newState = std::move(newState);
	}

	void StateManager::removeState()
	{
		isRemoving = true;
	}

	void StateManager::changeState()
	{
		if (isRemoving && !stateStack.empty())
		{
			stateStack.pop();

			if (!stateStack.empty())
				stateStack.top()->resume();

			isRemoving = false;
		}

		if (isAdding)
		{
			if( !stateStack.empty() )
			{
				if (isReplacing)
					stateStack.pop();
				else
					stateStack.top()->pause();
			}
			stateStack.push(std::move(newState));
			stateStack.top()->init();
			isAdding = false;
		}	
	}

	stateRef &StateManager::getActiveState()
	{
		return stateStack.top();
	}
}