#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Card.h>
#include <FlyingCar.h>
#include <Weapon.h>
#include <Pistol.h>

//int Add(int n1, int n2) {}
//int Add(int n1, int n2, int n3) {}

class BankAccount
{
public:
	BankAccount(float balance) : balance_(balance) {}

	BankAccount operator+(const BankAccount& other)
	{
		BankAccount result(balance_ + other.balance_);
		return result;
	}
private:
	float balance_;
};

void Counter()
{
	int i = 0;
	std::cout << i << " ";
	i++;
}

Pistol* MakeGun()
{
	// = new  means allocating heap memory
	Pistol* p1 = new Pistol(rand(), rand());
	return p1;
}

int main(int argc, char* args[])
{
	Pistol* p2 = MakeGun();
	Pistol* p3 = p2;

	int num = 5;
	int* pNum = &num;
	int& rNum = num;
	//std::cout << p2->calcDamage() << "\n";
	//make sure to delete dynamic memory
	//when you are done with it
	delete p2;
	p2 = nullptr;
	if (p2 != nullptr)
		std::cout << p2->calcDamage() << "\n";
	//std::cout << p3->calcDamage() << "\n";

	std::cout << num << "\n";
	//*pNum dereferences the pointer
	std::cout << *pNum << "\n";
	std::cout << rNum << "\n";

	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	//SECTIONS of memory:
	// stack: local variables
	// heap: dynamic variables
	// static: variables that live for the lifetime of the app
	// 
	//Weapon wpn(10, 40);
	Pistol pewpew;//stack object
	Pistol* pPistol = &pewpew;
	std::cout << pPistol->calcDamage() << "\n";
	std::cout << (*pPistol).calcDamage() << "\n";

	BankAccount b1(100);
	BankAccount b2(1000);
	BankAccount b3 = b1 + b2;

	Car road(1988, "Ford", "Mustang GT 5.0");
	FlyingCar xCar(2027, "Tesla", "CyberPlane", 100, 0);
	Car* currentCar = &road;//point it to road
	Car::reporting();
	//UPCASTING
	// pointing UP the hierarchy
	currentCar = &xCar;//point it to xCar
	std::cout << xCar.modelYear() << "\n";
	{
		std::vector<Car*> garage;
		garage.push_back(new Car(1988, "Ford", "Mustang GT 5.0"));//copies
		garage.push_back(new FlyingCar(2027, "Tesla", "CyberPlane", 100, 0));
		std::cout << "\n\nG's Garage:\n";
		for (auto& car : garage)
		{
			std::cout << car->vehicleInformation() << "\n";
		}

		for (int i = 0; i < garage.size(); i++)
		{
			delete garage[i];
		}
		garage.clear();
	}

	std::string hello = "Hello Week 3!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}