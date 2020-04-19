#include "DeckBuilder.h"
#include "BaseCardClass.h"


DeckBuilder::DeckBuilder()
{
	product = new Deck();

}

void DeckBuilder::producePartA(int amount) const
{
	for (size_t i = 0; i < amount; i++)
	{
		product->deckofCards.push_back(BaseCardClass ("Plus"));
	}
}

void DeckBuilder::producePartB(int amount) const{
	for (size_t i = 0; i < amount; i++)
	{
		product->deckofCards.push_back(BaseCardClass("Minus"));
	}
}

void DeckBuilder::producePartC(int amount) const{
	for (size_t i = 0; i < amount; i++)
	{
		product->deckofCards.push_back(BaseCardClass("Swap"));
	}
}

Deck* DeckBuilder::getDeck()
{
	Deck* retval = this->product;
	product = new Deck();
	return retval;
}

