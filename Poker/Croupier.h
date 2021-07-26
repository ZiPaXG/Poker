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
	Croupier(); // делает колоду
	vector<Cards> getRandCard(); // выдает 2 карты игроку
	void setDeckCr(); // создает 5 карт на столе
	vector<Cards>getDeckCr();
	void showDeck(vector<Cards>v1, int size);
	int ComboCard(vector<Cards> combo, vector<Cards>deckCr, int a);
	int checkCombination(vector<Cards>combo); // 1 - колода игрока, 2 - колода крупье, 3 - фаза игры
	void showCombination(int score);
	//int Street(vector<Cards> combo);
	int RoyalFlash(vector<Cards>combo);
	int CardPair(vector<Cards>combo);
	int StreetFlash(vector<Cards>combo);
	int Care(vector<Cards>combo);
	int FullHous(vector<Cards>combo);
	int HighCard(vector<Cards>combo);
	void setBank(vector<Player> players);
	float getBank();
	void setAllBet(vector<Player> players);
	void clearAllBet();
	float getAllBet();
	vector<Player> SetBet1(vector<Player>players, int n, float bet);
	vector<Player> SetBet2(vector<Player>players, int n, float bet);
	void getWin(vector<int>score, vector<int>point, vector <Player> players);
	vector<int> getDraw(vector<int> score, vector <Player> players, vector <int> id);
};