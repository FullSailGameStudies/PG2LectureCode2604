#pragma once
#include "Card.h"
class BlackjackCard : public Card
{
public:
	BlackjackCard(const std::string& face, const std::string& suit) :
		Card(face, suit)
	{	}

	//OVERRIDE
	//1) mark the base method with 'virtual'
	//2) add a new method in the derived
	//		it MUST match the signature of the base method
	//		optionally add 'override' to the derived method
	int Value() override;
};

