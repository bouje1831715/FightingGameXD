#pragma once
#include "Action.h"
class RogueCrounch :
	public Action
{
public:
	RogueCrounch(Entity* e, float forceAction = 0.0f);
	~RogueCrounch();
	int Update();
private:
	float forceAction;
};
