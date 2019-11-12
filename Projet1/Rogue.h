#pragma once
#include "Hero.h"
class Rogue :
	public Hero
{
public:
	Rogue();
	~Rogue();

	void ChangeAction(int enumIndex);
private:
	void addAnimations();
};

