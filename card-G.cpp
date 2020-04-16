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

		//player.displayHand();
		if (player.getPlayerHand().size() > 0) {
			cout << "Select more cards for your hand " << endl;
		}
		else {
			cout << "You need to select 5 card overall" << endl;
		}

		cin >> userInputs;
		int amountOfCard;
		cout << "enter the amount of card you would like " << endl;


		cin >> amountOfCard;
		if (amountOfCard > 5 || player.getPlayerHand().size() + amountOfCard > 5) {
			cout << "Too many cards Please try again\n" << endl;
			break;
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
		cout << ":have been added to your hand" << endl;

		cout << player.getPlayerHand().size();
	}
		
	if (player.getPlayerHand().size() >= 5) {

			while (player.getPlayerHand().size() > 0 || comPlayer.getCompHand().size()>0)
			{
				printClass.printEndround();
				player.displayPlayerPoints();
				cout << "Computer Player Points  " << comPlayer.getComputerPoints();
				
				BaseCardClass card = BaseCardClass();
				int cardIndex;
				if (comPlayer.getSelectedCard(card,cardIndex))
				{
					board.cardEffectOnByCompPlayer(card, player, comPlayer);
					cout << "\nCurrent Computer Points"<< comPlayer.getComputerPoints()<< endl;
					cout <<"cardIndex" <<cardIndex;
					if (cardIndex != 0 )
					{
					comPlayer.compHand.erase(comPlayer.compHand.begin() + cardIndex);

					}
					else
					{
						comPlayer.compHand.erase(comPlayer.compHand.begin());
					}
				}
				else
				{
					cout << "empty" << endl;
				}
				if (player.getPlayerHand().size() > 0)
				{
					player.displayHand();
					cout << "\n" << endl << "what card do you wanna play" << endl;

					cin >> cardToPlay;
					//comPlayer.displayCompHand();
					if (player.playerSelectCard(cardToPlay)) {
						board.cardEffectOnByPlayer(player.getPlayerHand().at(cardToPlay - 1), player, comPlayer);
						player.removeCard(cardToPlay);
					}

				}
				else
				{
					cout << "empty hand";
				}

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