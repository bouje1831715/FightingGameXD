#pragma once
#include "Hero.h"

enum Bullet { NORMAL, FIERY, SHREDDING, EXPLOSIVE };

class Hunter :
	public Hero
{
public:
	Hunter(string unitName, short baseDamage, short speed, short maxHP, short currentHP);
	~Hunter();
	DamageInfo GetDamage() override;
private:
	Bullet EquipedBullet;
};
