#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>
#include <iomanip>

void Counter(int num)
{
	//if(num < 10) //exit condition (base case)
	//{
	//	std::cout << num << " ";
	//	Counter(num + 1);//recursive condition
	//}

	if (num >= 10) return;

	std::cout << num << " ";
	Counter(num + 1);//recursive condition
	Console::Write(num, (ConsoleColor)(rand() % 8));
	std::cout << " ";
}

int main(int argc, char* args[])
{
	srand(static_cast<unsigned int>(time(NULL)));

	std::map<std::string, float> grades;
	//2 ways to add key-value pairs
	//  1) "easy" way. map[key] = value;
	grades["Bruce"] = 100;
	grades["Richard"] = 75;
	grades["Richard"] = 85;//overwrite

	//  2) "not-easy" way. map.insert(keyValuePair);
	std::pair<std::string, float> student =
		std::make_pair("Alfred", 50);
	grades.insert(student);
	//pair objects have a 'first' and a 'second'
	student.second = 60;
	auto wasInserted = grades.insert(student);//will NOT overwrite
	if (wasInserted.second)
	{
		std::cout << "Student was inserted.\n";
	}
	else
	{
		std::cout << "Student was NOT inserted. Do you want to overwrite the grade?\n";
	}
	std::vector<std::string> students = {
		"Garrett","Jacob","Christopher1","Christopher2","Kevin","Michael","Christian",
"Kien","Aidyn","Gregory","Larry","Rodriguez"
	};
	for (auto& name : students)
	{
		grades[name] = (rand() % 10001)/100.0f;
	}

	std::cout << "\n\nPG2 2604\n";
	for (auto it = grades.begin(); it != grades.end(); it++)
	{
		std::cout << it->first << " " << it->second << "\n";
	}

	std::cout << "\n\nPG2 2604\n";
	//use structured bindings
	for (auto& [name,grade] : grades)
	{
		std::cout << std::setw(15) << std::left << name << " ";
		Console::SetForegroundColor(
			//ternary operator
			(grade < 59.5) ? ConsoleColor::Red :
			(grade < 69.5) ? ConsoleColor::Yellow :
			(grade < 79.5) ? ConsoleColor::Cyan :
			(grade < 89.5) ? ConsoleColor::Magenta :
			ConsoleColor::Green
		);
		std::cout << std::setw(7) << std::right << grade << "\n";
		Console::Reset();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
	Counter(0);


	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}