#pragma once
#include "Action.h"
class MonkHoldAttack :
	public Action
{
public:
	MonkHoldAttack(Entity* e);
	~MonkHoldAttack();
	int Update();
private:
	float currentTime;
};

