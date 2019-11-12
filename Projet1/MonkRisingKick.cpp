#include "MonkRisingKick.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"
#include "Settings.h"

MonkRisingKick::MonkRisingKick(Entity* e) : Action(e)
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

MonkRisingKick::~MonkRisingKick()
{

}

int MonkRisingKick::Update()
{
	timeRemaining -= TimeManager::DeltaTime;
	parent->velY = -150.0f;
	if (parent->isFacingLeft)
		parent->velX = -1500.0f * timeRemaining - 200;
	else
		parent->velX = 1500.0f * timeRemaining + 200;

	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);

	if (!parent->isAirborne)
	{
		parent->gravityMult = 1;

		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (timeRemaining < 0)
	{
		if (parent->isAirborne)
			return (int)PlayerAction::FALLJUMPREADY;

		bool right = InputManager::GetKeyState(Keys::RIGHT);
		bool left = InputManager::GetKeyState(Keys::LEFT);
		bool down = InputManager::GetKeyState(Keys::DOWN);
		bool holdingJump = InputManager::GetKeyState(Keys::A);

		if (down)
			return (int)PlayerAction::CROUNCH;
		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	return -1;
}
