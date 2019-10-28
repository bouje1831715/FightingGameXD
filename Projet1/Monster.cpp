#include "Monster.h"

Monster::Monster(string unitName, short baseDamage, short speed, short maxHP, short currentHP = 0) : Character(unitName, baseDamage, speed, maxHP, currentHP)
{
}

Monster::~Monster()
{
}
