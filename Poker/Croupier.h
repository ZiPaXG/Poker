#pragma once
#include <vector>
#include <algorithm>
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
	void showDeck(vector<Cards>v1);
	vector<Cards>ComboCard(vector<Cards> combo, vector<Cards>deckCr, int a);
	int checkCombination(vector<Cards>combo); // 1 - ������ ������, 2 - ������ ������, 3 - ���� ����
	void showCombination(int score);
	//int Street(vector<Cards> combo);
	int RoyalFlash(vector<Cards>combo);
	int CardPair(vector<Cards>combo);
	int StreetFlash(vector<Cards>combo);
	int Care(vector<Cards>combo);
	int FullHous(vector<Cards>combo);
	int HighCard(vector<Cards>combo);
};