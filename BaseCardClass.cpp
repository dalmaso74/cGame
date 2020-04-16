#include "pch.h"
#include "BaseCardClass.h"
#include "string"
#include <iostream>


using namespace std;


BaseCardClass::BaseCardClass()
{
}

BaseCardClass::BaseCardClass(string name)
{
	cardType = name;
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

void BaseCardClass::stealCardAction()
{
	cout << "steal card not implmented";
}

void BaseCardClass::setCardpoint(int newCardValue)
{
	cardValue = newCardValue;
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
