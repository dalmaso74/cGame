#include "pch.h"
#include <string>
#include "BasePlayerClass.h"
#include <iostream>

using namespace std;


BasePlayerClass::BasePlayerClass()
{
}

void BasePlayerClass::cardAffect()
{
}


void BasePlayerClass::getVector(vector<BaseCardClass> card)
{
	for (size_t i = 0; i < card.size(); i++)
	{
		BaseCardClass c = card.at(i);
		cout << c.getCardType();
	}

}

void BasePlayerClass::drawFromDeck(vector<BaseCardClass> cards)
{
	playersHand.insert(playersHand.end(), cards.begin(), cards.end());
}

vector<BaseCardClass>BasePlayerClass::getPlayerHand()
{
	return playersHand;
}
void BasePlayerClass::playerSelectCard(int amount) {
	if (amount < getPlayerHand().size()) {
	cout << "choosen card    " << getPlayerHand().at(amount).getCardType() << endl;
	playersHand.erase(playersHand.begin() + (amount));
	}
}

void BasePlayerClass::setPlayerPoints(int points)
{
	playerPoints = points;
}


int BasePlayerClass::getPlayerPoints()
{
	 return playerPoints;
}

void BasePlayerClass::displayPlayerPoints()
{
	cout << getPlayerPoints() <<"   : Your Current Score Points"<<endl;
}

void BasePlayerClass::displayHand()
{
	cout << "these are your card\n";
	for (BaseCardClass c : getPlayerHand()) {
		cout <<  c.getCardType();
	}
	cout << "/n";
}


BasePlayerClass::~BasePlayerClass()
{
}
