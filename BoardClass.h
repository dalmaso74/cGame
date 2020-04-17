#pragma once
#include <fstream>
#include "Deck.h"
#include "BasePlayerClass.h"
#include "ComputerPlayer.h"
class BoardClass
{
public:
	BoardClass();
	int cardEffectOnByCompPlayer(BaseCardClass card,BasePlayerClass &player, ComputerPlayer &CompPlayer);
	int cardEffectOnByPlayer(BaseCardClass card, BasePlayerClass &player, ComputerPlayer &CompPlayer);
	

	ofstream outputFile;

};

