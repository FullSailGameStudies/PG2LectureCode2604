#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
	std::string base = Car::vehicleInformation();
	std::string derived = " Max Altitude: " + std::to_string(maxAlt_);
	return base + derived;
}