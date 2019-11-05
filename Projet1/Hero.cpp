#include "Hero.h"



Hero::Hero(string unitName, short baseDamage, short speed, short maxHP) : Character (unitName, baseDamage, speed, maxHP)
{
	IM = InputManager();
}


Hero::~Hero()
{

}

void Hero::ChangeAction(int enumIndex)
{
	
}
