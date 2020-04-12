#pragma once
#include "Deck.h"
#include <vector>
class BasePlayerClass
{
public:
	BasePlayerClass();
	void cardAffect();
	void drawFromDeck();
	void addToHand(BaseCardClass);
	vector<BaseCardClass> getPlayerHand();
	void displayHand();
	~BasePlayerClass();
private:
	int playerPoints = 0;
	vector<BaseCardClass> playersHand;
};

