#pragma once
#include "Hero.h"

enum Bullet { NORMAL, FIERY, SHREDDING, EXPLOSIVE };

class Hunter :
	public Hero
{
public:
	Hunter();
	~Hunter();
	Damage GetDamage() override;
private:
	Bullet EquipedBullet;
};

