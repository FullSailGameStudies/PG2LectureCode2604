#pragma once
#include "Weapon.h"
class Pistol :
    public Weapon
{
public:
	Pistol() : Weapon(5,10)
	{

	}
	int calcDamage() override
	{
		return 10;
	}
};

