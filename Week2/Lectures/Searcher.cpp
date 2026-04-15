#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenValue) const
{
	int index = NOT_FOUND;
	for (int i = 0; i < lights.size(); i++)
	{
		if (greenValue == lights.at(i).green)
		{
			index = i;
			break;
		}
	}
	return index;
}
