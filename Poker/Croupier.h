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
	Croupier(); // ������ ������
	vector<Cards> getRandCard(); // ������ 2 ����� ������
	void setDeckCr(); // ������� 5 ���� �� �����
	vector<Cards>getDeckCr();
	int checkCombination(vector<Cards>deck, vector<Cards>deckCr, int a); // 1 - ������ ������, 2 - ������ ������
};