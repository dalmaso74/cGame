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
	
			
	
	
}


bool ComputerPlayer::getSelectedCard(BaseCardClass &card)
{
	int cardToPlay;

	if (0 != compHand.size()) {
		cardToPlay = rand() % compHand.size();
	card = compHand.at(cardToPlay);
	return true;

	}
	return false;
}

void ComputerPlayer::cardAffect(BaseCardClass card)
{
	int tempPoints;
	if (card.getCardType() == "Minus")
	{
		tempPoints = card.minusCardAction(this->getComputerPoints());
	}
	else if (card.getCardType()== "Plus")
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

void ComputerPlayer::playCard(int card){

	cout<< "Computer played   "<<getCompHand().at(card).getCardType();
	compHand.erase(compHand.begin() + (card ));

}


void ComputerPlayer::setComputerPoints(int CompPoints)
{
	computerPoints += CompPoints;
	cout <<"setcompPLayer" <<computerPoints;
}

int ComputerPlayer::getComputerPoints()
{
	cout <<"GetCOMPUTER"<< computerPoints<<endl;
	return computerPoints;
	
}



vector<BaseCardClass> ComputerPlayer::getCompHand()
{
	return compHand;
}



ComputerPlayer::~ComputerPlayer()
{
}

