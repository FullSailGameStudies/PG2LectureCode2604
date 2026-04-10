#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//all default params have to be at the end of the param list
int Increment2(int n1, int n2 = 1, int num=0)//pass-by-value
{
	return num + 1;
}

void Increment(int& num)//pass-by-reference (ALIAS)
{
	num++;//changes the variable in a different scope
}
//use reference to prevent a copy
// when?
//	- the parameter is a class, especially if it's a container
void Printer(const std::vector<int>& nummies)
{
	//range-based (foreach) loop
	for (auto& nummie : nummies)
	{
		std::cout << nummie << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < nummies.size(); i++)
	{
		std::cout << nummies[i] << " ";
	}
	std::cout << "\n";
}

void Info(const std::vector<int>& numbers)
{
	//size() - # of elements in the vector
	//capacity() - length of internal array
	//size() <= capacity()
	std::cout << "Size: " << numbers.size();
	std::cout << " Capacity: " << numbers.capacity() << "\n";
}
int main(int argc, char* args[])
{
	Day2 day2; 
	std::vector<int> numbers;
	numbers.reserve(10);
	Info(numbers);//size: 0  capacity: 0?
	for (int i = 0; i < 15; i++)
	{
		numbers.push_back(i);
		Info(numbers);
	}
	std::vector<int> n2 = numbers;
	std::vector<int> n3(numbers);
	std::vector<int> n4;
	n4.reserve(numbers.size());
	for (int i = 0; i < numbers.size(); i++)
	{
		n4.push_back(numbers[i]);
	}
	//iterator
	//numbers.begin() - iterator to the first item
	//numbers.end() - iterator to the item AFTER the last item
	//iterator to last item = numbers.end() - 1
	//for (int i = 0; i < numbers.size(); i++)
	//{
	//	if (numbers[i] == 2)
	//	{
	//		numbers.erase(numbers.begin() + i);
	//		i--;
	//	}
	//}

	for (int i = 0; i < numbers.size(); )
	{
		if (numbers[i] == 2)
		{
			numbers.erase(numbers.begin() + i);
		}
		else
		{
			i++;
		}
	}
	for (int i = numbers.size() - 1; i >= 0; i--)
	{
		if (numbers[i] == 2)
		{
			numbers.erase(numbers.begin() + i);
		}
	}
	Printer(numbers);

	const double PI = 3.14159;

	int nummie = 5;
	Increment(nummie);
	Increment2(10);
	std::cout << nummie << "\n";

	int& numRef = nummie;
	numRef += 10;
	std::cout << nummie << "\n";

	Console::SetCursorPosition(10,5);

	Day1::CreateTargets_PartA_2(10);

	Target target1;
	target1.red = 255;
	target1.blue = target1.green = 0;
	target1.row = 10;
	target1.col = 5;
	bool isEqual = target1.Equals(5,10);
	if (isEqual) 
		std::cout << "Target hit!\n";
	else		 
		std::cout << "Target missed!\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("DC or Marvel? ");
			Console::WriteLine("DC. Duh!", ConsoleColor::Cyan);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			std::string name = Input::GetString("What is your name? ");
			Console::WriteLine("Your name is " + name + ".", ConsoleColor::Magenta);
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB_1();
			break;
		}
		case 9:
		{
			day2.PartB_2();
			break;
		}
		case 10:
		{
			day2.PartB_3();
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

