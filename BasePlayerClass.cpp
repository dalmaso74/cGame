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

void BasePlayerClass::displayHand()
{
	 getVector(playersHand);
}


BasePlayerClass::~BasePlayerClass()
{
}
