#pragma once
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
	void addToHand(BaseCardClass card);
	int getComputerPoints();
	~ComputerPlayer();
private:
	int computerPoints;
};

