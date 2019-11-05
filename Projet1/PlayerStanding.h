#pragma once
#include "Action.h"
class PlayerStanding :
	public Action
{
public:
	PlayerStanding();
	~PlayerStanding();
	int Update();
};

