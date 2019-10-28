#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	Monster(string unitName, short baseDamage, short speed, short maxHP, short currentHP);
	~Monster();
};

