// card-G.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include "BasePlayerClass.h"
#include "BoardClass.h"
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
	srand(time(NULL));
	Deck deck = Deck();
	int cardToPlay;
	int userInputs;
	int turnPLayed;
	BoardClass board = BoardClass ();
	BasePlayerClass player = BasePlayerClass();
	ComputerPlayer comPlayer = ComputerPlayer(deck);
	designClass printClass = designClass();

	//printClass.printWelcome();
	//printClass.printCardInfo();
	

	
	while (player.getPlayerHand().size() < 6) {

		if (player.getPlayerHand().size() > 0) {
			cout << " Select Cards for your hand " << endl;
		}
		else {
			cout << " Select your cards" << endl;
		}

		cin >> userInputs;
		int amountOfCard;
		cout << "enter the amount of card you would like " << endl;


		cin >> amountOfCard;
		if (amountOfCard > 5 || player.getPlayerHand().size() + amountOfCard > 5) {
			cout << "Too many cards Please try again\n" << endl;
			continue;
		}

		switch (userInputs) {
		case 1:
			player.drawFromDeck(deck.getPlusCard(amountOfCard));
			break;
		case 2:
			player.drawFromDeck(deck.getMinusCard(amountOfCard));
			break;
		case 3:
			player.drawFromDeck(deck.getstealCard(amountOfCard));
			break;
		default:
			break;
		}

		for (BaseCardClass c : player.getPlayerHand()) {
			cout << c.getCardType();
		}
		player.displayHand();

		/*for (BaseCardClass computerCards : comPlayer.getCompHand()) {
			cout << "Comp Cards" << computerCards.getCardType() << endl;
		}
		cout << "Your Oppenets points" << comPlayer.getComputerPoints() << endl;
		cout << "Your points " << player.getPlayerPoints() << endl;*/

		while (true)
		{
			cout << "\n" << endl << "what card do you wanna play" << endl;

			BaseCardClass card = BaseCardClass();
			player.displayPlayerPoints();
			if (comPlayer.getSelectedCard(card))
			{
				cout <<"CompPoints" <<comPlayer.getComputerPoints()<<endl;
				board.cardEffectOnByCompPlayer(card, player, comPlayer);
				cout << "CompPoints" <<comPlayer.getComputerPoints() << endl;

			}
			else
			{
				cout << "empty"<<endl;
			}
			
			cout << "\n" << endl << "what card do you wanna play" << endl;
			
			cin >> cardToPlay;
			
			player.playerSelectCard(cardToPlay);
			player.displayHand();


		}
	}
	

	
}

			/*	for (int i = 0; i < player.getPlayerHand().size(); i++){
					cardToPlay == player.getPlayerHand();{}
					cout << cardToPlay;*/
					//	}
						//		if (player.getPlayerHand().size() >= cardToPlay){
						//			cardToPlay = player.getPlayerHand().size();
						//		}