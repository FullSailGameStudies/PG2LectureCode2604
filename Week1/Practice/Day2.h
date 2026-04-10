#pragma once
#include <vector>
#include "Target.h"
#include "Map.h"

class Day2
{
public:
	void PartB_1();
	void PartB_2();
	void PartB_3();

private:
	//
	// Part B-1.1: Add a method declaration for GetLights
	//
	void GetLights(std::vector<Target>& targets) const;

	//
	// Part B-2.1: Add a method declaration for DrawLights
	//
	void DrawLights(const std::vector<Target>& targets, const Map& map) const;

	//
	// Part B-3.1: Add a method declaration for EraseLights
	//
	void EraseLights(std::vector<Target>& targets) const;

};

