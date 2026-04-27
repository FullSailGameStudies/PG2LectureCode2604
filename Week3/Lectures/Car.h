#pragma once
#include <string>
#include <iostream>
#include <Color.h>

class Car
{
public:
	//constructors
	//  NO return type (not even void)
	//  MUST have the same name as the class
	//  can have as many as you need
	//  can have any access modifier
	//  IF you do NOT create a ctor, the compiler will give you a default ctor
	//  IF you DO create a ctor, the compiler's default is no longer created
	
	//a default ctor (no parameters)
	//Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	//{   }

	Car(int year, std::string make, std::string model) :
		//member initialization list
		//   preferred way to initialize fields
		mModelYear(year),
		mMake(make),
		mModel(model),
		mFuelLevel(0),
		mMaxFuelLevel(15)
	{	
		//mModelYear = year;
		//mModel = model;
		//mMake = make;
	}

	virtual ~Car() = default;

	virtual std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

	//static methods do NOT have a'this' pointer
	// can ONLY access other STATIC members (data and methods)
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

	//non-static methods have a 'hidden' parameter
	//  'this' - is a pointer to the object it was called on
	//  can access non-static AND static members
	int modelYear() const
	{
		return this->mModelYear;
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

protected:
	//FIELDS:
	//  usually private to protect the data
	//  naming conventions:
	//		camelCasingNamingConvention
	//		add something to make it different than other variables
	//	    ex: m_  m   _
	int mModelYear;
	std::string mModel;
	std::string mMake;

	Color mExterior;


	int mFuelLevel;
	int mMaxFuelLevel;

	static int mNumberOfCarsMade; //shared by ALL cars
};

