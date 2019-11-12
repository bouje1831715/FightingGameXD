#pragma once
#include "Action.h"
class MonkJump :
	public Action
{
public:
	MonkJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canDoubleJump);
	~MonkJump();

	int Update();
private:
	bool doubleJumpReady;

	bool canPunch;
	bool canDropkick;
	bool canDoubleJump;
	bool canRoundhouse;
};

