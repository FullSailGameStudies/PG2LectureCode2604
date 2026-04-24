#pragma once
#include "Weapon.h"
class Pistol :
    public Weapon
{
public:
	Pistol() : Weapon(5,10)
	{

	}
	Pistol(int range, int damage) : Weapon(range, damage)
	{

	}
	int calcDamage() override
	{
		return 10;
	}
};

