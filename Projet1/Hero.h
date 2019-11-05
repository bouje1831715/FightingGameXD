#pragma once
#include "Character.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"

class Hero :
	public Character
{
public:
	Hero(string unitName, short baseDamage, short speed, short maxHP);
	~Hero();
	virtual void ChangeAction(int enumPlaceholder) = 0;
protected:
	InputManager IM;
	int vel;
	int acc;
	bool isJumping;
};

