#pragma once
#include "BaseCardClass.h"
#include <vector>

class Deck
{
public:
	Deck();
	void MinusCardGeneration(int cardValue);
	void PlusCardGeneration(int cardValue);
	void stealCardGeneration();
	void genrateCards();
	void removeDeck();
	vector <BaseCardClass> getDeck();
	void displayDeck();

	~Deck();
	
};

