#include "Croupier.h"
#include <windows.h>

using namespace std;

Croupier::Croupier()
{
	for (int i = 2; i <= 14; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mas.push_back(Cards(i, j));
		}
	}
}

vector<Cards> Croupier::getRandCard()
{
	int n1;
	
	vector<Cards> card;
	n1 = rand() % mas.size();
	card.push_back(mas[n1]);
	mas.erase(mas.begin() + n1);
	n1 = rand() % mas.size();
	card.push_back(mas[n1]);
	mas.erase(mas.begin()+n1);
	return card;
}

void Croupier::setDeckCr()
{
	for (int i = 0; i < 5; i++)
	{
		int n1;
		n1 = rand() % mas.size();
		deckCr.push_back(mas[n1]);
	}
}

vector<Cards> Croupier::getDeckCr()
{
	return deckCr;
}

void Croupier::showDeck(vector<Cards> v1)
{
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i].getCards() << " ";
	}
	cout << endl;
}

int Croupier::checkCombination(vector<Cards> deck, vector<Cards> deckCr, int a)
{
	// 10 вариантов
	vector<Cards> combo = deck;
	int score = 0;

	switch (a)
	{
	case 1:
		combo.insert(combo.end(), deckCr.begin(), deckCr.end()-2);
		
		// сортировка пузырьком
		for (int i = 0; i < combo.size() - 1; i++)
		{
			for (int j = 0; j < combo.size() - i - 1; j++)
			{
				if (combo[j].getName() > combo[j + 1].getName())
				{
					iter_swap(combo.begin()+j, combo.begin()+j+1);
				}
			}
		}

		showDeck(combo);
		score = RoyalFlash(combo);
		cout << score << endl;
		break;
	}

	return score;
}

void Croupier::showCombination(int score)
{
	switch (score)
	{
	case (High):
		cout << "У вас есть одна высокая карта!!!" << endl;
		break;
	case (Pair):
		cout << "У вас есть пара карт!!!" << endl;
		break;
	case (TwoPairs):
		cout << "У вас есть две пары карт!!!" << endl;
		break;
	case (Three):
		cout << "У вас есть три одинаковых карты!!!" << endl;
		break;
	case (Straight):
		cout << "У вас стрит!!!" << endl;
		break;
	case (Flush):
		cout << "У вас флеш!!!" << endl;
		break;
	case (FullHouse):
		cout << "У вас фулл хаос!!!" << endl;
		break;
	case (Four):
		cout << "У вас есть четыре одинаковые карты(каре)!!!" << endl;
		break;
	case (StraightFlush):
		cout << "У вас стрит флеш!!!" << endl;
		break;
	case (RoyalFlush):
		cout << "У вас роял флеш!!!" << endl;
		break;
	}
}

int Croupier::RoyalFlash(vector<Cards> combo)
{
	int t = 0; // счетчик
	int point = 0;
	int point1 = 0;
	int sizeVec = combo.size();

	// проверка на одинаковые масти
	for (int i = 0; i < 1; i++)
	{
		for (int j = i + 1; j < sizeVec; j++)
		{
			if (combo[i].getSuits() == combo[j].getSuits())
			{
				point1++;
			}
		}
	}

	// проверка на одинаковые значения в роял флеше
	for (int i = 10; i < 15; i++)
	{
		if (combo[t].getName() == i)
		{
			t++;
			point++;
		}
	}

	// проверка на сам роял флеш
	if (point == point1 + 1)
	{
		return 10;
	}

	//возвращает стрит
	else if (point == 5 && point1 != 4)
	{
		return 5;
	}

	// здесь спускается на уровень стрит флеша
	else if (point != 5 && point1 == 4)
	{
		t = StreetFlash(combo);
		return t;
	}

	// если нет совпадений
	else
	{
		t =  Care(combo);
		return t;
	}
}

int Croupier::StreetFlash(vector<Cards> combo)
{
	int point = 0;

	// проверка на одинаковые значения в стрит флеше
	for (int i = 0; i < combo.size(); i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (combo[i].getName() == combo[j].getName()-1)
			{
				point++;
			}
		}
	}
	
	// проверка на стрит флеш
	if (point == 4)
	{
		return 9;
	}

	else
	{
		return 6;
	}
}

int Croupier::Care(vector<Cards> combo)
{
	int t = 0;
	vector <int>point = {0, 0, 0, 0, 0};

	//проверка на каре
	for (int i = 0; i < combo.size(); i++)
	{
		for (int j = i + 1; j < combo.size(); j++)
		{
			if (combo[i].getName() == combo[j].getName())
			{
				point[i] += 1;
			}
		}
	}

	sort(point.begin(), point.end());
	
	//проверка на каре
	if (point[combo.size() - 1] == 3)
	{
		return 8;
	}

	// проверка на 3 одинаковые карты
	else if (point[combo.size() - 1] == 2)
	{
		t = FullHous(combo);
		return t;
	}
	
	else if (point[combo.size() - 1] == 1)
	{
		t = CardPair(combo);
		return t;
	}
}

int Croupier::FullHous(vector<Cards> combo)
{
	int point = 0;
	
	//проверка на фул хаос
	for (int i = 0; i < combo.size(); i++)
	{
		for (int j = i + 1; j < combo.size(); j++)
		{
			if (combo[i].getName() == combo[j].getName())
			{
				point++;
			}
			
			// проверка на фул хаос
			else if (j == 2 && point == 1)
			{
				return 7;
			}
		}
	}

	return 4;
}


int Croupier::CardPair(vector<Cards> combo)
{
	int t = 0;
	int point = 0;
	int point1 = 0;
	int x = 0;

	// проверка на пару карт
	for (int i = 0; i < combo.size(); i++)
	{
		for (int j = i + 1; j < combo.size(); j++)
		{
			if (combo[i].getName() == combo[j].getName())
			{
				point++;
			}
		}

		if (point == 1)
		{
			x = i+1;
			break;
		}
	}

	for (int i = x; i < combo.size(); i++)
	{
		for (int j = i + 1; j < combo.size(); j++)
		{
			if (combo[i].getName() == combo[j].getName())
			{
				point1++;
			}
		}

		if (point1 == 1)
		{
			break;
		}
	}

	// проверка на две пару
	if (point == point1)
	{
		return 3;
	}

	// проверка на пару
	else if (point == 1 || point1 == 1)
	{
		return 2;
	}

	// поиск наивысшей карты
	else if (point != 1 && point1 != 1)
	{
		t = HighCard(combo);
		return t;
	}
}

int Croupier::HighCard(vector<Cards> combo)
{
	int point = 0;

	for (int i = 0; i < combo.size(); i++)
	{
		if (point < combo[i].getName())
		{
			point = combo[i].getName();
		}
	}

	return 1;
}