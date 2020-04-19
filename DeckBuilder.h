#pragma once
#include "BuilderClass.h"
#include "Deck.h"
class DeckBuilder : public BuilderClass
{
private:
	Deck* product;
public:
	DeckBuilder();
	void producePartA(int amount) const override;
	void producePartB(int amount) const override;
	void producePartC(int amount) const override;

	Deck* getDeck();
};

