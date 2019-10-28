#pragma once
#include "Character.h"
class Hero :
	public Character
{
public:
	Hero(string unitName, short baseDamage, short speed, short maxHP, short currentHP);
	~Hero();
};

