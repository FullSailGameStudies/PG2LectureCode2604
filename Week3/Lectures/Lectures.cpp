#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Card.h>
#include <FlyingCar.h>

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

int main(int argc, char* args[])
{
	BankAccount b1(100);
	BankAccount b2(1000);
	BankAccount b3 = b1 + b2;

	FlyingCar xCar(2027, "Tesla", "CyberPlane", 100, 0);

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