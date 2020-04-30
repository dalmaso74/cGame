#include "Deck.h"
#include "pch.h"
#include <iostream>


Deck::Deck()
{
	//genrateCards();
	//deckofCards;
}

void Deck::MinusCardGeneration(int cardValue)
{
	BaseCardClass card = BaseCardClass("Minus");
	card.setCardpoint(cardValue);
	deckofCards.push_back(card);
	
}

void Deck::PlusCardGeneration(int cardValue)
{
	BaseCardClass card = BaseCardClass("Plus");
	card.setCardpoint(cardValue);
	deckofCards.push_back(card);
}

void Deck::stealCardGeneration()
{
	BaseCardClass card = BaseCardClass("Swap");
	deckofCards.push_back(card);
}

void Deck::genrateCards()
{
	for (int i = 0; i < 4; i++) {
		int cardValue;
		cardValue = 3;
		PlusCardGeneration(cardValue);

	}
	for (int i = 4; i < 8; i++) {
		int cardValue;
		cardValue = 1;
		PlusCardGeneration(cardValue);
	}
	for (int i = 8; i < 12; i++)
	{
		int cardValue;
		cardValue = 3;
		MinusCardGeneration(cardValue);

	}
	for (int i = 12; i < 16; i++)
	{
		int cardValue;
		cardValue = 1;
		MinusCardGeneration(cardValue);
	}
	for (int i = 16; i < 20; i++)
	{
		stealCardGeneration();
	}
}

void Deck::removeDeck()
{
	return;
}


vector <BaseCardClass> Deck::getDeck()
{
	return deckofCards;
}

vector <BaseCardClass> Deck::getMinusCard(int amount)
{
	vector<BaseCardClass> retrival = vector <BaseCardClass>();
	for (size_t i = 0; i < deckofCards.size(); i++)
	{
		if (retrival.size() == amount) {
			return retrival;
		}
		if (deckofCards.at(i).getCardType() == "Minus") {
			retrival.push_back(deckofCards.at(i));
		}
	}
	return retrival;
//		BaseCardClass c = BaseCardClass("Minus");
//	for (size_t i = 0; i < deckofCards.size(); i++)
//	{
//		if (deckofCards.at(i).getCardType = "Minus")
//		{
	//		return deckofCards.at(i);
		//}
//	}// return c;
}


vector <BaseCardClass> Deck::getPlusCard(int amount)
{
	vector<BaseCardClass> retrival = vector <BaseCardClass>();
	for (size_t i = 0; i < deckofCards.size(); i++)
	{
		if (retrival.size() == amount) {
			return retrival;
		}
		if (deckofCards.at(i).getCardType() == "Plus") {
			retrival.push_back(deckofCards.at(i));
		}
	}
	return retrival;
}

vector <BaseCardClass> Deck::getstealCard(int amount)
{
	vector<BaseCardClass> retrival = vector <BaseCardClass> ();
	for (size_t i = 0; i < deckofCards.size(); i++)
	{
		if (retrival.size() == amount){
			return retrival;
		}
		if (deckofCards.at(i).getCardType() == "Steal"){	
			retrival.push_back(deckofCards.at(i));
		}
		
	}
	
	return retrival;
}
vector <BaseCardClass> Deck::getSwapCard(int amount)
{
	vector<BaseCardClass> retrival = vector <BaseCardClass>();
	for (size_t i = 0; i < deckofCards.size(); i++)
	{
		if (retrival.size() == amount) {
			return retrival;
		}
		if (deckofCards.at(i).getCardType() == "Swap") {
			retrival.push_back(deckofCards.at(i));
		}

	}
	cout << "swap card selected";
	return retrival;
}
void Deck::displayDeck()
{
	cout << "diplay deck unfished";
}


Deck::~Deck()
{
}
