#pragma once
#include <vector>
#include <algorithm>
#include "Cards.h"
#include "Player.h"

enum Combination
{
	High = 1, Pair, TwoPairs, Three, Straight, Flush, FullHouse, Four, StraightFlush, RoyalFlush
};
class Croupier
{
private:
	vector<Cards> mas;
	vector<Cards> deckCr;
	float bank = 0;
	float allBet = 50;

public:
	Croupier(); // ������ ������
	vector<Cards> getRandCard(); // ������ 2 ����� ������
	void setDeckCr(); // ������� 5 ���� �� �����
	vector<Cards>getDeckCr();
	void showDeck(vector<Cards>v1, int size);
	int ComboCard(vector<Cards> combo, vector<Cards>deckCr, int a);
	int checkCombination(vector<Cards>combo); // 1 - ������ ������, 2 - ������ ������, 3 - ���� ����
	void showCombination(int score);
	int RoyalFlash(vector<Cards>combo);
	int CardPair(vector<Cards>combo);
	int Care(vector<Cards>combo);
	int FullHous(vector<Cards>combo);
	int HighCard(vector<Cards>combo);
	void setBank(vector<Player> players);
	float getBank();
	void setAllBet(vector<Player> players);
	void clearAllBet();
	float getAllBet();
	vector<Player> SetBet1(vector<Player>players, int n, int bet);
	vector<Player> SetBet2(vector<Player>players, int n, int bet);
	vector<Player> getWin(vector<int>score, vector <Player> players, Croupier c1, vector<Player> playersMain);
	vector<int> getDraw(vector<int> score, vector <Player> players, vector <int> id, vector<Cards> deckCr);
	void setMainAllBet();
	void newCards();
	//void setDeck(); ��� debaging-�
};