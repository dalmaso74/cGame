#include <iostream>
#include "BoardClass.h"

int BoardClass::cardEffectOnByCompPlayer(BaseCardClass card, BasePlayerClass player,ComputerPlayer compPlayer)
{	
	int tempPoints;
	if (card.getCardType() == "Minus")
	{
		tempPoints = card.minusCardAction(player.getPlayerPoints());
		player.setPlayerPoints(tempPoints);
	}
	else if (card.getCardType() == "Plus")
	{
		compPlayer.computerPoints = card.plusCardAction(compPlayer.getComputerPoints());
		//cout << tempPoints << endl;
		//compPlayer.setComputerPoints(tempPoints);
		cout << " else statement in the computer class might be wrong";
	}
	return 0;
	
}
int BoardClass::cardEffectOnByPlayer(BaseCardClass card, BasePlayerClass player,ComputerPlayer COmpplayer)
{
	//int tempPoints;
	//if (card.getCardType() == "Minus")
	//{
	//	tempPoints = card.minusCardAction(player.getComputerPoints());
	//	player.setComputerPoints(tempPoints);
	//}
	//else if (card.getCardType() == "Plus")
	//{
	//	tempPoints = card.plusCardAction(player.getComputerPoints());
	//	cout << " else statement in the computer class might be wrong";
	//	player.setComputerPoints(tempPoints);
	//}
	//
	return 0;
}


