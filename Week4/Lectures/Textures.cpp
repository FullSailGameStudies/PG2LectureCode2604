#include "Textures.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Textures::LoadSubtextures()
{
	//
	// Part A-1
	//
	std::ifstream inFile("character_robot_sheetHD.csv");
	if (inFile.is_open())
	{
		std::getline(inFile, imageFile_);
		while (not inFile.eof())
		{
			//read 1 line
			std::string line;
			std::getline(inFile, line);
			//std::cout << line << "\n";

			//parse the line
			//  use multiple getlines to get the name, x, y, width, height
			std::stringstream lineStream(line);

			SubTexture subT;

			std::getline(lineStream, subT.name, '?');

			std::string data;
			std::getline(lineStream, data, '?');
			subT.x = std::stoi(data);

			std::getline(lineStream, data, '?');
			subT.y = std::stoi(data);

			std::getline(lineStream, data, '?');
			subT.width = std::stoi(data);

			std::getline(lineStream, data, '?');
			subT.height = std::stoi(data);
			
			subTextures_.push_back(subT);

			maxWidth_ = std::max(maxWidth_, subT.width);
			maxHeight_ = std::max(maxHeight_, subT.height);
		}
		inFile.close();
		return true;
	}
	else
		std::cout << "File could not be opened.\n";

	return false;
}

bool Textures::LoadSpritesheet(SDL_Renderer* renderer)
{
	spriteSheet_ = new PG2Texture(renderer);
	return spriteSheet_->LoadFromFile(imageFile_);
}

SDL_Rect Textures::GetTextureSource(int index)
{
	SDL_Rect rect{ 0,0,0,0 };
	if (index >= 0 && index < subTextures_.size())
	{
		rect.x = subTextures_[index].x;
		rect.y = subTextures_[index].y;
		rect.w = subTextures_[index].width;
		rect.h = subTextures_[index].height;
	}
	return rect;
}

void Textures::Render(SDL_Rect* texSrc, SDL_Rect* dest, SDL_RendererFlip flip)
{
	spriteSheet_->Render(texSrc, dest, 0, 0, flip);
}
