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
	timeRemaining = 0.350f;
}

RogueRoll::~RogueRoll()
{
}

int RogueRoll::Update()
{
	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < 0)
		return (int)PlayerAction::STAND;
}