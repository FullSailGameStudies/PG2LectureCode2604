#pragma once
#include <string>
#include <iostream>

class Car
{
public:
	Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{	}
	std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//getter (accessor)
	//  const methods
	//  return type matches the type of the field
	//  usually don't have parameters
	//  simply return the field
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	//  void return types
	//  purpose is to update a field
	//  has at least 1 parameter that is used
	//		to change the field
	//	cannot be a const method
	//  good place for validation logic
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

private:
	//FIELDS:
	//  usually private to protect the data
	//  naming conventions:
	//		camelCasingNamingConvention
	//		add something to make it different than other variables
	//	    ex: m_  m   _
	int mModelYear;
	std::string mModel;
	std::string mMake;


	int mFuelLevel;
	int mMaxFuelLevel;

	static int mNumberOfCarsMade; //shared by ALL cars
};

