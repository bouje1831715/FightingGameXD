#pragma once
#include "Action.h"
class MonkCrounching :
	public Action
{
public:
	MonkCrounching(Entity* e, float forceAction);
	~MonkCrounching();
	int Update();
private:
	float forceAction;
	float forceActionCounter;
};

