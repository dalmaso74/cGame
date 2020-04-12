#pragma once
#include "Deck.h"
class ComputerPlayer
{
public:
	ComputerPlayer();
	void selectCompHand(Deck& deck);
	void computerMoves();
	void cardAffect(BaseCardClass card);
	void addToHand(BaseCardClass card);
	int getComputerPoints();
	vector<BaseCardClass> getCompHand();
	void showHand();
	~ComputerPlayer();
private:
	int computerPoints;
};

