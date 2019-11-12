#pragma once
#include "Action.h"
class HunterJump :
	public Action
{
public:
	HunterJump(Entity* e);
	~HunterJump();
	int Update();
};

