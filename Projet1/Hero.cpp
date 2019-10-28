#include "Hero.h"



Hero::Hero(string unitName, short baseDamage, short speed, short maxHP, short currentHP = 0) : Character (unitName, baseDamage, speed, maxHP, currentHP)
{
}


Hero::~Hero()
{
}
