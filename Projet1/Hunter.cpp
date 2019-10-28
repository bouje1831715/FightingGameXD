#include "Hunter.h"



Hunter::Hunter()
{
}


Hunter::~Hunter()
{
}

Damage Hunter::GetDamage()
{
	Damage damage;
	switch (EquipedBullet) {
	case FIERY:
		damage = { FIRE, 30, 6 };
		break;
	case SHREDDING:
		damage = { PHYSICAL, 20, 3, {DOT}, {60}};
		break;
	case EXPLOSIVE:
		damage = { FIRE, 80, 30 };
		break;
	default:
		damage = { PHYSICAL, 40, 5 };
		break;
	}
	return damage;
}
