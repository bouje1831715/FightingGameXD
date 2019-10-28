#pragma once
#include <memory>
#include <stack>

#include "../State.h"

namespace GameView
{
	typedef std::unique_ptr<State> stateRef;

	class StateManager
	{
	public:
		StateManager();
		~StateManager();

		void addState(stateRef state, bool isReplacing = true);
		void removeState();

		void changeState();

		stateRef &getActiveState();
	private:
		std::stack<stateRef> stateStack;
		stateRef newState;

		bool isRemoving;
		bool isAdding;
		bool isReplacing;
	};
}
