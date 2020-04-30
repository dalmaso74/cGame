#include "pch.h"
#include "BaseCardClass.h"
#include "string"
#include <iostream>


using namespace std;


BaseCardClass::BaseCardClass()
{
	cardValue = rand() % 5 + 1;
}

BaseCardClass::BaseCardClass(string name)
{
	cardType = name;
	cardValue = rand() % 5 + 1;
}

int BaseCardClass::plusCardAction(int playerPoints)
{
	//adding value of players Point
	return playerPoints + cardValue;
}

int BaseCardClass::minusCardAction(int playerPoints)
{
	//minus value off players Point
	int newplayerPoints;

	newplayerPoints = playerPoints - cardValue;

	if (newplayerPoints < 1)
	{
		newplayerPoints =playerPoints + 1;
	}
	else
	{
		return newplayerPoints;
	}
}


void BaseCardClass::setCardpoint(int newCardValue)
{
	cardValue = newCardValue;
}

int BaseCardClass::addPoints(int playerPoints)
{
	//add point that will be used by the steal card
	return playerPoints + 1;

}

int BaseCardClass::getCardPoints()
{
	return cardValue;
}

string BaseCardClass::getCardType()
{//rerutn the cards name 
	return cardType;
}

BaseCardClass::~BaseCardClass()
{
}
