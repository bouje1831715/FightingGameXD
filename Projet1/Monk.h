#pragma once
#include "Hero.h"

class Monk : public Hero
{
public:
	Monk();
	~Monk();
	void ChangeAction(int enumPlaceholder) override;
private:
	void AddAnimations();
};

