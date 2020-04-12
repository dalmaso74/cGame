#include "pch.h"
#include "ComputerPlayer.h"
#include <iostream>
using namespace std;

ComputerPlayer::ComputerPlayer()
{
}

void ComputerPlayer::selectCompHand(Deck& deck)
{
	//BaseCardClass selectTheCard;

}

void ComputerPlayer::computerMoves()
{
	//
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
		tempPoints = card.plusCardAction(this->computerPoints);
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
	return vector<BaseCardClass>();
}

void ComputerPlayer::showHand()
{

}

ComputerPlayer::~ComputerPlayer()
{
}

