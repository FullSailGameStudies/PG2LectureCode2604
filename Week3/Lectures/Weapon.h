#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	virtual void showMe();

	//a pure virtual function
	virtual int calcDamage() = 0;

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

