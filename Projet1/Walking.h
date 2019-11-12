#pragma once
#include "Action.h"
class Walking :
	public Action
{
public:
	Walking(Entity* e);
	~Walking();
	int Update();
private:
	float turnCharacter;
};

