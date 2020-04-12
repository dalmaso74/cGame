#pragma once
#include "BaseCardClass.h"
#include <vector>

class Deck
{
public:
	Deck();
	vector<BaseCardClass> deckofCards;
	void MinusCardGeneration(int cardValue);
	void PlusCardGeneration(int cardValue);
	void stealCardGeneration();
	void genrateCards();
	void removeDeck();
	vector <BaseCardClass> getDeck();
	vector <BaseCardClass> getMinusCard(int amount);
	vector <BaseCardClass> getPlusCard(int amount);
	vector <BaseCardClass> getstealCard(int amount);
	void displayDeck();
		

	~Deck();
	
};

