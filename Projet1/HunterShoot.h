#pragma once
#include "Action.h"
class HunterShoot :
	public Action
{
public:
	HunterShoot(Entity* e);
	~HunterShoot();
	int Update();
private:
	float timeRemaining;
};

