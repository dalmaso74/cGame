#include "pch.h"
#include <fstream>
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
	vector <BaseCardClass> stealCard = deck.getstealCard(1);
	vector <BaseCardClass> plusCard = deck.getPlusCard(2);
	vector <BaseCardClass> minusCard = deck.getMinusCard(2);
	vector <BaseCardClass> swapCard = deck.getSwapCard(0);
	
	retrival.insert(retrival.begin(), plusCard.begin(),	 plusCard.end());
	retrival.insert(retrival.begin(), stealCard.begin(), stealCard.end());
	retrival.insert(retrival.begin(), minusCard.begin(), minusCard.end());
	retrival.insert(retrival.begin(), swapCard.begin(), swapCard.end());
		
	return retrival;
}

void ComputerPlayer::drawForComputer(vector<BaseCardClass> cards){

	compHand.insert(compHand.end(), cards.begin(), cards.end());
}

void ComputerPlayer::drawFromDeck(Deck& deck){
	
	vector <BaseCardClass>  selectedCards = selectCompHand(deck);
	drawForComputer(selectedCards);
}



bool ComputerPlayer::getSelectedCard(BaseCardClass &card,int &cardIndex)
{
	int cardToPlay;

	if (0 != compHand.size()) {
	cardToPlay = rand() % compHand.size()+1;
	cardToPlay--;
	//cout << cardToPlay;
	//displayCompHand();
	card = compHand.at(cardToPlay);
	cardIndex = cardToPlay;
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
	this->computerPoints = CompPoints;
}

void ComputerPlayer::addToComp(BaseCardClass card)
{
	compHand.push_back(card);
}

void ComputerPlayer::displayCompHand()
{
	for (size_t i = 0; i < compHand.size(); i++){
		cout << "\nComputers hand" << compHand.at(i).getCardType()<< i << endl;
	}
	//for (BaseCardClass card: getCompHand())
	//{
	//	cout<<"\nComputers hand"<<card.getCardType()<<endl;
	//}
}

int ComputerPlayer::getComputerPoints()
{
	return computerPoints;
	
}



vector<BaseCardClass> ComputerPlayer::getCompHand()
{
	return compHand;
}

void ComputerPlayer::setCompPlayerHand(vector<BaseCardClass> card)
{
	this->compHand = card;
}



ComputerPlayer::~ComputerPlayer()
{
}

