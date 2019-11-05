#include "PlayerStanding.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"

PlayerStanding::PlayerStanding() : Action()
{

}


PlayerStanding::~PlayerStanding()
{

}

int PlayerStanding::Update()
{
	if (InputManager::GetKeyState(Keys::RIGHT))
		return (int)PlayerAction::WALK;
	else if (InputManager::GetKeyState(Keys::LEFT))
		return (int)PlayerAction::CROUNCH;
	else
		return -1;
}
