#include "RogueRoll.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"


RogueRoll::RogueRoll(Entity* e) : Action(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->isFacingLeft = false;
	else if (left)
		parent->isFacingLeft = true;
	parent->isAirborne = true;
	timeRemaining = 0.60f;
}

RogueRoll::~RogueRoll()
{
}

int RogueRoll::Update()
{
	if (parent->isFacingLeft)
		parent->accelerate(-2);
	else
		parent->accelerate(2);

	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < 0)
	{
		parent->isFacingLeft = !parent->isFacingLeft;
		return (int)PlayerAction::STAND;
	}
	return - 1;
}