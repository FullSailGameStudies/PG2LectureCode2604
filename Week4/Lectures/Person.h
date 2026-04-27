#pragma once
#include <string>
#include <fstream>
class Person
{
public:
	Person(const std::string& nm, int ag) : name(nm), age(ag)
	{	}

	//2 methods for deserializing
	//1. constructor (will simpy call deserialize)
	//2. deserialize
	Person(const std::string& lineOfData, char delim)
	{
		DeserializeCSV(lineOfData, delim);
	}

	void DeserializeCSV(const std::string& lineOfData, char delim);
	void SerializeCSV(std::ofstream& file, char delim);

private:
	std::string name;
	int age;

};

