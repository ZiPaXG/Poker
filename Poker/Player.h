#pragma once
#include <vector>
#include "Cards.h"
#include <Windows.h>

using namespace std;

class Player
{
private:
	string name;
	float money;
	float bet = 0;
	vector<Cards>deck;

public:
	Player(string _name, float _money) : name{ _name }, money{_money}
	{

	};

	void setDeck(vector<Cards>card); // создает колоду
	void showDeck(); // выводит колоду
	string getNameP();
	void setMoney(float _money);
	vector<Cards>getDeck();
	void setBet(float a); // делает ставку
	float getBet();
	Player checkBet(int a, Player pl, float allBet);
	Player Call(Player pl, float allBet);
	Player Raise(Player pl, float allBet);
	Player VaBank(Player pl1);
	float getMoney();
	vector<Player> clearBet(vector<Player> players);
};