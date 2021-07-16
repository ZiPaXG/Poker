#pragma once
#include <vector>
#include "Cards.h"
#include <Windows.h>

using namespace std;

class Player
{
private:
	string name;
	int money;
	int bet = 0;
	vector<Cards>deck;

public:
	Player(string _name, int _money) : name{ _name }, money{_money}
	{

	};

	void setDeck(vector<Cards>card); // ������� ������
	void showDeck(); // ������� ������
	vector<Cards>getDeck();
	void setBet(int a); // ������ ������
};
