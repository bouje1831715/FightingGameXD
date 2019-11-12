#include "Character.h"



Character::Character(string unitName, short baseDamage, short maxHP)
{
	this->UnitName = unitName;
	this->BaseDamage = baseDamage;
	this->MaxHP = maxHP;
	this->CurrentHP = maxHP;
}


Character::~Character()
{
}

DamageInfo Character::GetDamage()
{
	return { DamageType::PHYSICAL, BaseDamage };
}


bool Character::ApplyDamage(short damage)
{
	CurrentHP -= damage;
	return CurrentHP > 0 ? true : false;
}
