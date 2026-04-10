#include "Day2.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"

//
// Part B-1.2: Add a method definition for GetLights
//
void Day2::GetLights(std::vector<Target>& targets) const
{
	for (int row = 0; row < 48; row++)
	{
		for (int col = 0; col < 48; col++)
		{
			Target target;
			target.col = col;
			target.row = row;
			target.red = rand() % 256;
			target.blue = rand() % 256;
			target.green = rand() % 256;

			targets.push_back(target);
		}
	}
}



//
// Part B-2.2: Add a method definition for DrawLights
//
void Day2::DrawLights(const std::vector<Target>& targets, const Map& map) const
{
	//for (int i = 0; i < targets.size(); i++)
	//{
	//	map.DrawCell(targets[i].col, targets[i].row, targets[i].red, targets[i].green, targets[i].blue);
	//}
	for (auto& target : targets)
	{
		map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
	}
	for (auto iter = targets.begin(); iter != targets.end(); iter++)
	{
		map.DrawCell(iter->col, iter->row, iter->red, iter->green, iter->blue);

	}
}


//
// Part B-3.2: Add a method definition for EraseLights
//
void Day2::EraseLights(std::vector<Target>& targets) const
{
	//reverse for loop
	for (int i = targets.size() - 1; i >= 0; i--)
	{
		if (targets[i].red < 100)
		{
			targets.erase(targets.begin() + i);
		}
	}
}

void Day2::PartB_1()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-1 Goal: Pass by reference", ConsoleColor::Green);
		Console::WriteLine("Write a method called GetLights to fill the vector with Target objects.");
		Console::WriteLine("\t there should be 48 rows with 48 Target objects per row.");
		Console::WriteLine("\t Give each target a random color.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);

		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			for (auto& target : lights)
			{
				map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
			}

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day2::PartB_2()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-2 Goal: const parameters", ConsoleColor::Green);
		Console::WriteLine("Write a method called DrawLights to call DrawCell for each Target.");
		Console::WriteLine("\t NOTE: pass the vector and engine by reference AND as const.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);

		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			//
			// Part B-2.3: call DrawLights
			//
			DrawLights(lights, map);

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day2::PartB_3()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-3"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-3 Goal: erasing in a loop", ConsoleColor::Green);
		Console::WriteLine("Write a method called EraseLights. Pass the 'lights' variable to it.");
		Console::WriteLine("\tInside the method, erase any light whose red value is less than 100.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);

		//
		// Part B-3.3: call EraseLights
		//
		EraseLights(lights);


		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			//
			// Part B-2.3: call DrawLights
			//
			DrawLights(lights, map);

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}
