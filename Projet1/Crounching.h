#pragma once
#include "Action.h"
class Crounching :
	public Action
{
public:
	Crounching(Entity* e, float forceAction = 0.0f);
	~Crounching();
	int Update();
private:
	float forceAction;
};

