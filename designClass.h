#pragma once
#include <fstream>
#include "BasePlayerClass.h"
#include "ComputerPlayer.h"

class designClass
{
public:
	designClass();
	ofstream outputFile;
	void diplayWinner(BasePlayerClass player,ComputerPlayer compPlay);
	void printWelcome();
	void printCardInfo();
	void printEndround();
	void printEndGame();
};

