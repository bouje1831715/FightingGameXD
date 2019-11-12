#pragma once
#include "Action.h"
class Jumping : 
	public Action
{
public:
	Jumping(Entity* e, bool canDoubleJump = false);
	~Jumping();

	int Update();
private:
	bool canDoubleJump;
	bool doubleJumpReady;
};

