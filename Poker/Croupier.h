#pragma once
#include <vector>
#include "Cards.h"

enum Combination
{
	High = 1, Pair, TwoPairs, Three, Straight, Flush, FullHouse, Four, StraightFlush, RoyalFlush
};
class Croupier
{
private:
	vector<Cards> mas;
	vector<Cards> deckCr;

public:
	Croupier(); // делает колоду
	vector<Cards> getRandCard(); // выдает 2 карты игроку
	void setDeckCr(); // создает 5 карт на столе
	vector<Cards>getDeckCr();
	int checkCombination(vector<Cards>deck, vector<Cards>deckCr, int a); // 1 - колода игрока, 2 - колода крупье
};