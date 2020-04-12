#pragma once
#include "Deck.h"
#include <string>
#include <vector>

class BasePlayerClass
{
public:
	BasePlayerClass();
	void cardAffect();
	void getVector(vector<BaseCardClass> card);
	void drawFromDeck(vector<BaseCardClass> cards);
	vector<BaseCardClass> getPlayerHand();
	void displayHand();
	~BasePlayerClass();
private:
	int playerPoints = 0;
	vector<BaseCardClass> playersHand;
};

