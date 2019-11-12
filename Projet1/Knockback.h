#pragma once
#include "Action.h"

class Knockback :
	public Action
{
public:
	Knockback(int initialForceX, int initialForceY, Entity* e);
	~Knockback();

	int Update();
};

