#pragma once
#include "Action.h"
class Falling :
	public Action
{
public:
	Falling(Entity* e);
	~Falling();
	int Update();
};

