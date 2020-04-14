#include "pch.h"
#include "ComputerPlayer.h"
#include <iostream>
using namespace std;


ComputerPlayer::ComputerPlayer(Deck &deck)
{
	drawFromDeck(deck);
	
}


vector <BaseCardClass> ComputerPlayer::selectCompHand(Deck &deck)
{
	//BaseCardClass selectTheCard;
	int selected = 0;
	//while (compHand.size()< 5)
	//{
	vector <BaseCardClass> retrival = vector <BaseCardClass>();
	vector <BaseCardClass> plusCard = deck.getPlusCard(2);
	vector <BaseCardClass> minusCard = deck.getMinusCard(2);
	vector <BaseCardClass> stealCard = deck.getstealCard(1);
	
	retrival.insert(retrival.begin(), plusCard.begin(),	 plusCard.end());
	retrival.insert(retrival.begin(), minusCard.begin(), minusCard.end());
	retrival.insert(retrival.begin(), stealCard.begin(), stealCard.end());
		
	return retrival;
}

void ComputerPlayer::drawForComputer(vector<BaseCardClass> cards){

	compHand.insert(compHand.end(), cards.begin(), cards.end());
}

void ComputerPlayer::drawFromDeck(Deck& deck){
	
	vector <BaseCardClass>  selectedCards = selectCompHand(deck);
	drawForComputer(selectedCards);
}

void ComputerPlayer::computerMoves()
{
	for (size_t i = 0; i < length; i++)
	{

	}
	
}



void ComputerPlayer::cardAffect(BaseCardClass card)
{
	int tempPoints;
	if (card.getCardType() == "minus")
	{
		tempPoints = card.minusCardAction(this->getComputerPoints());
	}
	else
	{
		tempPoints = card.plusCardAction(this->getComputerPoints());
		cout << " else statement in the computer class might be wrong";
	}
	if (tempPoints == NULL)
	{
		cout << "currently null try again";
	}
	else
	{
		tempPoints = computerPoints;
		cout << " The current Points is " + this->getComputerPoints();
	}
}

void ComputerPlayer::addToHand(BaseCardClass card)
{
}

int ComputerPlayer::getComputerPoints()
{
	return computerPoints;
}



vector<BaseCardClass> ComputerPlayer::getCompHand()
{
	return compHand;
}



ComputerPlayer::~ComputerPlayer()
{
}

