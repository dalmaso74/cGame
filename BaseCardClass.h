#pragma once
#include <string>
using namespace std;

class BaseCardClass
{
public:
	BaseCardClass(string card);
	int plusCardAction(int playerPoints);
	int minusCardAction(int playerPoints);
	void stealCardAction();
	void setCardpoint(int newCardValue);
	void setCardPoint(int newCardValue);
	int getCardPoints();
	string getCardType();

	~BaseCardClass();

private:
	string cardType;
	int cardValue;
};

