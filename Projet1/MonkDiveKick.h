#pragma once
#include "Action.h"
class MonkDiveKick :
	public Action
{
public:
	MonkDiveKick(Entity* e);
	~MonkDiveKick();

	int Update();
private:
	float countDown;
};

