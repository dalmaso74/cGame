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
	return playerPoints + cardValue;
	//playersPoints = playersPoints + cardValue;
}

int BaseCardClass::minusCardAction(int playerPoints)
{
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
	return playerPoints + 1;

}

int BaseCardClass::getCardPoints()
{
	return cardValue;
}

string BaseCardClass::getCardType()
{
	return cardType;
}

BaseCardClass::~BaseCardClass()
{
}
