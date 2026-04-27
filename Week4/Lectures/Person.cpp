#include "Person.h"
#include <sstream>

void Person::DeserializeCSV(const std::string& lineOfData, char delim)
{
	std::stringstream dataStream(lineOfData);
	std::getline(dataStream, name, delim);

	std::string data;
	std::getline(dataStream, data, delim);
	age = std::stoi(data);
}

//serialize should ONLY be responsible
//for writing the data (step 2)
//it should NOT open or close the file
void Person::SerializeCSV(std::ofstream& file, char delim)
{
	//save the name and age to the file separated by the delim
	file << name << delim << age;
}
