// card-G.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BasePlayerClass.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include "BaseCardClass.h"
#include "designClass.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Deck deck = Deck();
	int userInputs;
	BasePlayerClass player = BasePlayerClass();
	ComputerPlayer comPlayer = ComputerPlayer();
	designClass printClass = designClass();

	printClass.printWelcome();
	printClass.printCardInfo();

	cout << "Please choose 5 card of your liking  " << endl;
	while (player.getPlayerHand().size() < 5 && comPlayer.getCompHand().size() < 5)
	{
		if (player.getPlayerHand().size() > 0){
			cout << " Select Cards for your hand \n";
		}
		else{
			cout << " Select your cards";
		}

		cin >> userInputs;
		int amountOfCard;
		cout << "enter the amount of card you would like ";


		cin >> amountOfCard;
		if (amountOfCard > 5 || player.getPlayerHand().size() &&
			comPlayer.getCompHand().size() + amountOfCard> 5){
			cout << "get more cards \n";
			continue;
		}
		
		switch (userInputs)	{
		case 1:
			player.drawFromDeck(deck.getMinusCard(amountOfCard));
			break;
		case 2:
			player.drawFromDeck(deck.getPlusCard(amountOfCard));
			break;
		case 3:
			player.drawFromDeck(deck.getstealCard(amountOfCard));
			break;
		default:
			break;
		}
	}

	for (BaseCardClass c : player.getPlayerHand()){
		cout << c.getCardType();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
