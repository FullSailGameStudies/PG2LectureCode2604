#pragma once
#include <vector>
#include <Card.h>
class Deck
{
public:
	Deck()
	{
		//TODO: call the MakeCards method
	}
	Deck(const std::vector<Card>& cards_)
		: cards_(cards_)
	{}

	bool HasCards() const { return not cards_.empty(); }

	const std::vector<Card>& Cards() const { return cards_; }
	void Cards(const std::vector<Card>& cards)
	{
		if (not cards.empty() and cards.size() == 52)
			cards_ = cards;
	}

private:
	std::vector<Card> cards_;
public:
};

