#include "Deck.h"

void Deck::MakeCards()
{
	Cleanup();

	//create the 13 cards for 4 suits
	std::vector<std::string> suits{ "Hearts", "Clubs", "Diamonds", "Spades" };
	std::vector<std::string> faces{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	for (auto& suit : suits)
	{
		for (auto& face : faces)
		{
			cards_.push_back(new Card(suit, face));
		}
	}
}
