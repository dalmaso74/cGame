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
	void setPlayerHand(vector<BaseCardClass> card);
	bool playerSelectCard (int card);
	void setPlayerPoints(int points);
	int getPlayerPoints();
	void displayPlayerPoints();
	void displayHand();
	void removeCard(int amount);
	void addPoints(int points);
	void addToHand(BaseCardClass card);
	~BasePlayerClass();
private:
	int playerPoints = 10;
	vector<BaseCardClass> playersHand;
};

