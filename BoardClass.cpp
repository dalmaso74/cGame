#include <iostream>
#include <fstream>
#include "BoardClass.h"


BoardClass::BoardClass()
{
outputFile.open("GameFile.txt");

}

int BoardClass::cardEffectOnByCompPlayer(BaseCardClass card, BasePlayerClass &player,ComputerPlayer &compPlayer)
{	
	int tempPoints;
	if (card.getCardType() == "Minus")
	{
		tempPoints = card.minusCardAction(player.getPlayerPoints());
		player.setPlayerPoints(tempPoints);
	}
	else if (card.getCardType() == "Plus")
	{
		tempPoints = card.plusCardAction(compPlayer.getComputerPoints());
		//cout << tempPoints << endl;
		compPlayer.setComputerPoints(tempPoints);
	}
	else if (card.getCardType() == "Steal")
	{
		int CardtoSteal;
		if (compPlayer.getCompHand().size() == 0)
		{
			outputFile << "player hand is empty thus computer gets +1 points\n" << endl;
			tempPoints = card.addPoints(compPlayer.getComputerPoints());

			compPlayer.setComputerPoints(tempPoints);
		}
		else
		{
			CardtoSteal = rand() % player.getPlayerHand().size() + 1;

			compPlayer.addToComp(player.getPlayerHand().at(CardtoSteal - 1));
			player.removeCard(CardtoSteal);
		}
	}

	cout <<"\n\n"<<"Computer Played "<<card.getCardType() << endl;
	outputFile << "\n" << "Computer Played  " << card.getCardType() << endl;
	outputFile.close();

	return 0;
	
}
int BoardClass::cardEffectOnByPlayer(BaseCardClass card, BasePlayerClass &player,ComputerPlayer &compPlayer)
{
	int tempPoints;
	if (card.getCardType() == "Plus")
	{
		tempPoints = card.plusCardAction(player.getPlayerPoints());
		player.setPlayerPoints(tempPoints);
	}
	else if (card.getCardType() == "Minus")
	{
		tempPoints = card.minusCardAction(compPlayer.getComputerPoints());
		//cout << tempPoints << endl;
		compPlayer.setComputerPoints(tempPoints);

	}
	else if (card.getCardType() == "Steal")
	{
		int CardtoSteal;
		if (compPlayer.getCompHand().size()==0)
		{
			cout << "computer hand is empty thus you get +1 points\n";
			outputFile << "computer hand is empty thus you get +1 points\n"<<endl;
			tempPoints=card.addPoints(player.getPlayerPoints());
			
			player.setPlayerPoints(tempPoints);
		}
		else
		{
			compPlayer.displayCompHand();
			cout << "Card to steal";
			outputFile << "Card to steal" << endl;
			cin >> CardtoSteal;
			player.addToHand(compPlayer.getCompHand().at(CardtoSteal -1));
			compPlayer.compHand.erase(compPlayer.compHand.begin()+ (CardtoSteal -1));
		}
		
	}
	else if (card.getCardType() == "Swap") {
		player.displayHand();
		swapImplemantation(player,compPlayer);
		player.displayHand();
	}
	
	return 0;
	outputFile.close();
}

void BoardClass::swapImplemantation(BasePlayerClass &player, ComputerPlayer &comPlayer){

	vector<BaseCardClass> swap = vector <BaseCardClass> ();
	swap = player.getPlayerHand();
	player.setPlayerHand(comPlayer.getCompHand());
	comPlayer.setCompPlayerHand(swap);
}


void BoardClass::setBuilder(BuilderClass* builder)
{
	this->builder = builder;
}

void BoardClass::buildDeck(int plus, int minus, int steal){
	this->builder->producePartA(plus);
	this->builder->producePartB(minus);
	this->builder->producePartC(steal);
}



