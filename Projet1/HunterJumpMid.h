#pragma once
#include "Action.h"
class HunterJumpMid :
	public Action
{
public:
	HunterJumpMid(Entity* e);
	~HunterJumpMid();
	int Update();
};

