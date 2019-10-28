#pragma once
#include <string>
#include <vector>
using namespace std;

enum DamageType { PHYSICAL, FIRE, COLD, THUNDER, POISON };
enum ExtraEffect {STUN, DOT};

struct Damage 
{
public:
	DamageType Type;
	short Amount;
	short KnockBack = 10;
	vector<ExtraEffect> Effects = { };
	vector<short> Magnitudes = { };
};

class Character
{
public:
	Character(string unitName, short baseDamage, short speed, short hp, short currentHP);
	~Character();
	
	///<summary>Return true if the character is still alive</summary>
	bool ApplyDamage(short damage);
	virtual Damage GetDamage();

protected:
	string UnitName;
	short CurrentHP;
	short MaxHP;
	short BaseDamage;
	short Speed;
};

