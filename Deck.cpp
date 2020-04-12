#include "Deck.h"
#include "pch.h"
#include <iostream>

vector<BaseCardClass> deckofCards;

Deck::Deck()
{
	genrateCards();
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
	BaseCardClass card = BaseCardClass("Steal");
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

void Deck::displayDeck()
{
	cout << "diplay deck unfished";
}


Deck::~Deck()
{
}
