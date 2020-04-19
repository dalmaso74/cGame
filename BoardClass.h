#pragma once
#include <fstream>
#include "Deck.h"
#include "BuilderClass.h"
#include "BasePlayerClass.h"
#include "ComputerPlayer.h"
class BoardClass
{
private:
	BuilderClass* builder;
public:
	BoardClass();
	int cardEffectOnByCompPlayer(BaseCardClass card,BasePlayerClass &player, ComputerPlayer &CompPlayer);
	int cardEffectOnByPlayer(BaseCardClass card, BasePlayerClass &player, ComputerPlayer &CompPlayer);
	void setBuilder(BuilderClass* builder);
	
	void buildDeck(int plus,int minus, int steal);
	void swapImplemantation(BasePlayerClass &player,ComputerPlayer &comPlayer);
	ofstream outputFile;

};

