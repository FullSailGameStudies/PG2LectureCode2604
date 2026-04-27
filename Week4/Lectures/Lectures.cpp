#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>
#include <sstream> //for the stringstream class
#include <Person.h>


int main(int argc, char* args[])
{
	//<fstream>
	// ifstream, ofstream

	//1) open the file
	//	where is the file? (path)
	std::string fileName = "2604.csv";
	std::string path = "C:/temp/2604/";
	std::string finalPath = path + fileName;
	//ONLY IF the path exists, 
	// it will create the file
	// it will NOT create the path if it doesn't exists
	std::ofstream outFile(finalPath);
	char delimiter = '$';
	if (outFile.is_open())
	{
		//2) write to the file
		// << - insertion operator
		outFile << "Batman is the best." << delimiter << 5;
		outFile << delimiter << 13.7 << delimiter << "true";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}

	//3) close the file
	//  good professional practice: 
	//		close the file ASAP!!!
	outFile.close();

	//1) open the file
	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//use getline to read lines from the file
		//read from the stream UNTIL it finds a '\n' OR
		//  reaches the end of the stream
		std::string line;
		std::getline(inFile, line);

		std::cout << line << "\n";

		//process the line (parsing)
		std::string data;
		std::stringstream lineStream(line);
		//read from the stream UNTIL it finds a delimiter OR
		//  reaches the end of the stream
		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		std::getline(lineStream, data, delimiter);
		int iData = std::stoi(data);
		std::cout << iData << "\n";

		std::getline(lineStream, data, delimiter);
		double dData = std::stod(data);
		std::cout << dData << "\n";

		std::getline(lineStream, data, delimiter);
		//use a try-catch to handle exceptions
		try
		{
			bool bData = std::stoi(data);
		}
		catch (const std::exception&)
		{
			//handle the exception
			std::cout << "Error processing bool bData: " << data << "\n";
		}
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}

	//3) close the file
	//  good professional practice: 
	//		close the file ASAP!!!
	inFile.close();

	Person bruce("Bruce Wayne", 35);
	std::ofstream personFile("bruce.csv");
	if (personFile.is_open())
	{
		bruce.SerializeCSV(personFile, '@');
	}
	else
	{
		std::cout << "File could not be opened.\n";
	}
	personFile.close();

	Person csvPerson("Robin;12", ';');
	std::ifstream inpersonFile("bruce.csv");
	if (inpersonFile.is_open())
	{
		//read a line from the file
		std::string line;
		std::getline(inpersonFile, line);

		//create a person with the line
		Person inPerson(line, '@');
	}
	else
	{
		std::cout << "File could not be opened.\n";
	}
	inpersonFile.close();

    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
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
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}