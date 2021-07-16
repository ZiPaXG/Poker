#pragma once
#include <iostream>

using namespace std;

class Cards
{
private:
	int name;
	int suits;

public:
	Cards(int name, int suits) : name{ name }, suits{ suits }
	{

	};
	string getCards();
	int getName();
	int getSuits();
};