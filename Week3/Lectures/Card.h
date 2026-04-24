#pragma once
#include <string>
class Card
{
public:
	Card(const std::string& face, const std::string& suit) :
		face_(face),
		suit_(suit)
	{

	}
	virtual ~Card() = default;

	virtual int Value();

	//getters and setters can be defined in the header
	const std::string& GetFace() const
	{
		return face_;
	}
	void SetFace(const std::string& face)
	{
		if (face.size() > 0 and face.size() < 3)
		{
			face_ = face;
		}
	}
	const std::string& Suit() const
	{
		return suit_;
	}
	void Suit(const std::string& suit)
	{
		if (suit == "Hearts" or suit == "Clubs" or
			suit == "Diamonds" or suit == "Spades")
		{
			suit_ = suit;
		}
	}


private:
	std::string face_, suit_;
};

