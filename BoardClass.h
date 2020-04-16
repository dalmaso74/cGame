#pragma once
#include "Deck.h"
#include "BasePlayerClass.h"
#include "ComputerPlayer.h"
class BoardClass
{
public:
	int cardEffectOnByCompPlayer(BaseCardClass card,BasePlayerClass &player, ComputerPlayer &CompPlayer);
	int cardEffectOnByPlayer(BaseCardClass card, BasePlayerClass &player, ComputerPlayer &CompPlayer);


};

