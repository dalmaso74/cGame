#include "pch.h"
#include <fstream>
#include <string>
#include "BasePlayerClass.h"
#include <iostream>

using namespace std;

ofstream outputFile;

BasePlayerClass::BasePlayerClass()
{
	outputFile.open("GameFile.txt",fstream::app);
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
void BasePlayerClass::setPlayerHand(vector<BaseCardClass> card)
{	
	this->playersHand = card;
}
bool BasePlayerClass::playerSelectCard(int amount) {
	if (amount <= getPlayerHand().size()) {
	cout << "choosen card    " << getPlayerHand().at(amount-1).getCardType() << endl;
	outputFile << "choosen card    " << getPlayerHand().at(amount - 1).getCardType() << endl;
	//playersHand.erase(playersHand.begin() + (amount-1));
	return true;
	}
	return false;
}

void BasePlayerClass::setPlayerPoints(int points)
{
	this->playerPoints = points;
}


int BasePlayerClass::getPlayerPoints()
{
	 return playerPoints;
}

void BasePlayerClass::displayPlayerPoints()
{
	cout <<"Your Current Score Points  "<< getPlayerPoints()<<endl;
}

void BasePlayerClass::displayHand()
{
	for (BaseCardClass c : getPlayerHand()) {
		cout <<  c.getCardType();
		outputFile << c.getCardType();

	}
	outputFile << "\n";
	cout << "\n";
}

void BasePlayerClass::removeCard(int amount)
{
	playersHand.erase(playersHand.begin() + (amount-1));

}



void BasePlayerClass::addToHand(BaseCardClass card){
	playersHand.push_back(card);
}


BasePlayerClass::~BasePlayerClass()
{
}
