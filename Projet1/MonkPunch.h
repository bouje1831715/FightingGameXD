#pragma once
#include "Action.h"
class MonkPunch :
	public Action
{
public:
	MonkPunch(Entity* e);
	~MonkPunch();

	int Update();

private:
	float timeRemaining;
	float currentVelY;
};

