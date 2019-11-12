#pragma once
#include "Action.h"
class Standing :
	public Action
{
public:
	Standing(Entity* e);
	~Standing();
	int Update();
};

