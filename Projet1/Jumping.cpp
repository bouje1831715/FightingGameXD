#include "Jumping.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"

Jumping::Jumping(Entity* e, bool canDoubleJump) : Action(e)
{		
	parent->isAirborne = true;
	parent->velY = 0;
	parent->jump();
	parent->gravityMult = 1;
	this->canDoubleJump = canDoubleJump;
}

Jumping::~Jumping()
{

}

int Jumping::Update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool jump = InputManager::GetKeyState(Keys::A);

	if (!parent->isAirborne)
	{
		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (canDoubleJump)
	{
		if (!jump)
			doubleJumpReady = true;
		else if (jump && doubleJumpReady)
			return (int)PlayerAction::SECONDJUMP;
	}

	if (right && !left)
		parent->accelerate(0.5);
	else if (left && !right)
		parent->accelerate(-0.5);

	if (InputManager::GetKeyState(X))
		return (int)PlayerAction::BASICATTACK;

	return -1;
}

