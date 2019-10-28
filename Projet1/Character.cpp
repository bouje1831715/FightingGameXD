#include "Character.h"



Character::Character(string unitName, short baseDamage, short speed, short maxHP, short currentHP = 0)
{
	this->UnitName = unitName;
	this->BaseDamage = baseDamage;
	this->Speed = speed;
	this->MaxHP = maxHP;

	if (currentHP > 0 && currentHP < MaxHP)
		this->CurrentHP = currentHP;
	else
		this->CurrentHP = maxHP;
}


Character::~Character()
{
}

Damage Character::GetDamage()
{
	return { DamageType::PHYSICAL, BaseDamage };
}

bool Character::ApplyDamage(short damage)
{
	CurrentHP -= damage;
	return CurrentHP > 0 ? true : false;
}
