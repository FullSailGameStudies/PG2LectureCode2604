#pragma once
#include <vector>
#include "Light.h"

const int NOT_FOUND = -1;

class Searcher
{
public:
	//
	// Part B-1
	//
	
	// purpose: find the index of a light w/ a specific green value

	/// <summary>
	/// Performs a linear search over the provided vector of Light objects to find a light matching the specified green value.
	/// </summary>
	/// <param name="lights">A const reference to the vector of Light objects to search through.</param>
	/// <param name="greenValue">The green value to match against each Light.</param>
	/// <returns>The index of the first matching Light in the vector, or -1 if no match is found.</returns>
	int LinearSearch(const std::vector<Light>& lights, int greenValue) const;
};

