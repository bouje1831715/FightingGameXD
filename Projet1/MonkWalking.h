#pragma once
#include "Action.h"
class MonkWalking :
	public Action
{
public:
	MonkWalking(Entity* e);
	~MonkWalking();
	int Update();
};

