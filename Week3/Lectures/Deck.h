#pragma once
#include <vector>
#include <Card.h>
class Deck
{
public:
	Deck()
	{
		//TODO: call the MakeCards method
		MakeCards();
	}
	Deck(const std::vector<Card*>& cards_)
		: cards_(cards_)
	{}
	//destructors 
	virtual ~Deck()
	{
		//cleanup heap memory
		Cleanup();
	}
	void Cleanup()
	{
		for (int i = 0; i < cards_.size(); i++)
		{
			delete cards_[i];
		}
		cards_.clear();
	}

	bool HasCards() const { return not cards_.empty(); }

	const std::vector<Card*>& Cards() const { return cards_; }
	void Cards(const std::vector<Card*>& cards)
	{
		if (not cards.empty() and cards.size() == 52)
			cards_ = cards;
	}

	void MakeCards();

private:
	std::vector<Card*> cards_;
public:
};

