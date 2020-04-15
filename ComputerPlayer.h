#pragma once
#include "pch.h"
#include <vector>
#include "Deck.h"
class ComputerPlayer
{
public:

	vector<BaseCardClass> compHand;

	ComputerPlayer(Deck &deck);
	vector <BaseCardClass> selectCompHand(Deck& deck);
	void drawForComputer(vector<BaseCardClass> cards);
	void computerMoves();
	void drawFromDeck(Deck& deck);
	vector <BaseCardClass> getCompHand();
	void cardAffect(BaseCardClass card);
	void playCard(int card);
	bool getSelectedCard(BaseCardClass &card);
	void setComputerPoints(int CompPoint);
	int getComputerPoints();
	~ComputerPlayer();
	int computerPoints ;
private:
};

