// card-G.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include "BasePlayerClass.h"
#include "BoardClass.h"
#include "ComputerPlayer.h"
#include "Deck.h"
#include "BuilderClass.h"
#include "DeckBuilder.h"
#include <fstream>
#include "BaseCardClass.h"
#include "designClass.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int main()
{
	srand(time(NULL));
	DeckBuilder* deckBuilder = new DeckBuilder();
	BoardClass boardClass = BoardClass();
	boardClass.setBuilder(deckBuilder);
	boardClass.buildDeck(8,8,4);
	Deck deck = *deckBuilder->getDeck();
	
	int cardToPlay;
	int userInputs;
	int turnPLayed;
	BoardClass board = BoardClass ();
	BasePlayerClass player = BasePlayerClass();
	ComputerPlayer comPlayer = ComputerPlayer(deck);
	designClass printClass = designClass();
	ofstream outputFile;

	//printClass.printWelcome();
	//printClass.printCardInfo();
	//if (outputFile.fail())
	//{
	//
	outputFile.open("GameFile.txt");
	//cerr << "Error with opening file" << endl;
	outputFile << "Game report file" << endl;
//	}
	
	while (player.getPlayerHand().size() < 5) {

		//player.displayHand();
		if (player.getPlayerHand().size() > 0) {
			cout << "Select more cards for your hand " << endl;
			outputFile << "Select more cards for your hand" << endl;
		}
		else {
			cout << "You need to select 5 card overall" << endl;
			outputFile << "You need to select 5 card overall" << endl;
		}

		cin >> userInputs;
		int amountOfCard;
		cout << "enter the amount of card you would like " << endl;


		cin >> amountOfCard;
		if (amountOfCard > 5 || player.getPlayerHand().size() + amountOfCard > 5|| userInputs >=4) {
			cout << "Wrong value Please try again\n" << endl;
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
					outputFile << c.getCardType();
				}
		
				outputFile << "   these are you choosen card";
				cout << ":have been added to your hand" << endl;
//		cout << player.getPlayerHand().size();
		//outputFile.close();
	}
		
	if (player.getPlayerHand().size() >= 5) {


			while (player.getPlayerHand().size() > 0 || comPlayer.getCompHand().size()>0)
			{
				//ofstream outputFile;
				printClass.printEndround();
				player.displayPlayerPoints();
				cout << "Computer Player Points  " << comPlayer.getComputerPoints() << endl;
				outputFile << "Computer player Points    " << comPlayer.getComputerPoints() << endl;
				outputFile << "Your Points   " << player.getPlayerPoints()<<endl;
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
					outputFile << "\n" << "what card do you want to play";
					cout << "\n" << endl << "what card do you wanna play" << endl;

					cin >> cardToPlay;
					//comPlayer.displayCompHand();
					if (player.playerSelectCard(cardToPlay)) {
						outputFile << "you played " << player.playerSelectCard(cardToPlay)<<endl;
						if (player.getPlayerHand().at(cardToPlay-1).getCardType()=="Swap")
						{
							BaseCardClass swap = player.getPlayerHand().at(cardToPlay - 1);
							player.removeCard(cardToPlay);
							board.cardEffectOnByPlayer(swap, player, comPlayer);
						}
						else
						{
							board.cardEffectOnByPlayer(player.getPlayerHand().at(cardToPlay - 1), player, comPlayer);
							player.removeCard(cardToPlay);
							cout << "gerge is gat";
						}
					}


				}
				else
				{
					//cout << "Your hand is empty" << endl;
				}

			}
			printClass.diplayWinner(player,comPlayer);
			printClass.printEndGame();
			outputFile.close();
		}

	
}

			/*	for (int i = 0; i < player.getPlayerHand().size(); i++){
					cardToPlay == player.getPlayerHand();{}
					cout << cardToPlay;*/
					//	}
						//		if (player.getPlayerHand().size() >= cardToPlay){
						//			cardToPlay = player.getPlayerHand().size();
						//		}