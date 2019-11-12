#pragma once
#include "Action.h"
class MonkRisingKick :
	public Action
{
public:
	MonkRisingKick(Entity* e);
	~MonkRisingKick();
	int Update();
private:
	float timeRemaining;
};

