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
	void playerSelectCard (int card);
	void setPlayerPoints(int points);
	int getPlayerPoints();
	void displayPlayerPoints();
	void displayHand();

	~BasePlayerClass();
private:
	int playerPoints = 10;
	vector<BaseCardClass> playersHand;
};

