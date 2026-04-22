#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	FlyingCar(int year, std::string make, std::string model, 
		      int maxAlt, int alt) :
		//call the base class ctor
		Car(year, make, model),
		maxAlt_(maxAlt),
		alt_(alt)
	{
		//do NOT duplicate the base ctor logic
	}

	int MaxAltitude() const { return maxAlt_; }
	int Altitude() const { return alt_; }
	void MaxAltitude(int maxAlt)
	{
		if (maxAlt > 0 && maxAlt < 70000)
			maxAlt_ = maxAlt;
	}
	void Altitude(int alt)
	{
		if (alt >= 0 && alt <= maxAlt_)
			alt_ = alt;
	}

private:
	int maxAlt_, alt_;

};

