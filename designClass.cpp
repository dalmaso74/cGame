#include "designClass.h"
#include <iostream>
using namespace std;


void designClass::diplayWinner(BasePlayerClass player, ComputerPlayer compPlay){
	if (player.getPlayerPoints() > compPlay.getComputerPoints())
	{
		cout << "Player wins";
	}
	if (player.getPlayerPoints() < compPlay.getComputerPoints()) {
		cout << "Computer Player wins" << endl;
	}
	else
	{
		cout << "We have a Draw"<<endl;
	}
}

void designClass::printWelcome()
{
	cout << "-------------------------------WELCOME To The Game ------------------------------\n"
			"-----------------------This is a card Game with 3 Cards types--------------------\n"
			"---------------------------Choose 5 cards of your liking-------------------------\n"
			"------------------------------The game keeps going-------------------------------\n"
			"---------------------------till both player have no------------------------------\n"
			"---------------------------------cards to play-----------------------------------\n"
		<< endl;
}	

void designClass::printCardInfo()
{
	cout << "Plus allows you to add points to your total score\n"
			"Minus allows you to Subtract points from your oppents score\n"
			"Steal allows you to take from the oppents hand\n"
			
			"Please choose 5 card of your liking \n"
			"Press 1 for Plus Cards"
			"Press 2 for Minus Cards"
			"Press 3 for Steal Cards"
			<<endl;
}

void designClass::printEndround()
{
	cout << "---------------------------------New round---------------------------\n"<<endl;
}

void designClass::printEndGame()
{
	cout << "---------------------------------Thank you for playing---------------------------\n"
			"---------------------------Game results should be in the file--------------------\n" <<endl;
}
