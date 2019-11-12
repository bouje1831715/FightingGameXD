#pragma once
#include "action.h"
class Entity;
class MonkSecondJump :
	public Action
{
public:
	MonkSecondJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick);
	~MonkSecondJump();

	int Update();
private:
	bool canRoundhouse;
	bool canPunch;
	bool canDropkick;
};

