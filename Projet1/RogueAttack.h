#pragma once
#include "Action.h"
class RogueAttack :
	public Action
{
public:
	RogueAttack(Entity* e);
	~RogueAttack();

	int Update();

	float timeRemaining;
};

