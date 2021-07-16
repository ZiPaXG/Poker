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
	// 10 ���������
	vector<Cards> combo = deck;
	int score = 0;

	switch (a)
	{
	case 1:
		combo.insert(combo.end(), deckCr.begin(), deckCr.end()-2);
		
		// ���������� ���������
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
		cout << "� ��� ���� ���� ������� �����!!!" << endl;
		break;
	case (Pair):
		cout << "� ��� ���� ���� ����!!!" << endl;
		break;
	case (TwoPairs):
		cout << "� ��� ���� ��� ���� ����!!!" << endl;
		break;
	case (Three):
		cout << "� ��� ���� ��� ���������� �����!!!" << endl;
		break;
	case (Straight):
		cout << "� ��� �����!!!" << endl;
		break;
	case (Flush):
		cout << "� ��� ����!!!" << endl;
		break;
	case (FullHouse):
		cout << "� ��� ���� ����!!!" << endl;
		break;
	case (Four):
		cout << "� ��� ���� ������ ���������� �����(����)!!!" << endl;
		break;
	case (StraightFlush):
		cout << "� ��� ����� ����!!!" << endl;
		break;
	case (RoyalFlush):
		cout << "� ��� ���� ����!!!" << endl;
		break;
	}
}

int Croupier::RoyalFlash(vector<Cards> combo)
{
	int t = 0; // �������
	int point = 0;
	int point1 = 0;
	int sizeVec = combo.size();

	// �������� �� ���������� �����
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

	// �������� �� ���������� �������� � ���� �����
	for (int i = 10; i < 15; i++)
	{
		if (combo[t].getName() == i)
		{
			t++;
			point++;
		}
	}

	// �������� �� ��� ���� ����
	if (point == point1 + 1)
	{
		return 10;
	}

	//���������� �����
	else if (point == 5 && point1 != 4)
	{
		return 5;
	}

	// ����� ���������� �� ������� ����� �����
	else if (point != 5 && point1 == 4)
	{
		t = StreetFlash(combo);
		return t;
	}

	// ���� ��� ����������
	else
	{
		t =  Care(combo);
		return t;
	}
}

int Croupier::StreetFlash(vector<Cards> combo)
{
	int point = 0;

	// �������� �� ���������� �������� � ����� �����
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
	
	// �������� �� ����� ����
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

	//�������� �� ����
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
	
	//�������� �� ����
	if (point[combo.size() - 1] == 3)
	{
		return 8;
	}

	// �������� �� 3 ���������� �����
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
	
	//�������� �� ��� ����
	for (int i = 0; i < combo.size(); i++)
	{
		for (int j = i + 1; j < combo.size(); j++)
		{
			if (combo[i].getName() == combo[j].getName())
			{
				point++;
			}
			
			// �������� �� ��� ����
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

	// �������� �� ���� ����
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

	// �������� �� ��� ����
	if (point == point1)
	{
		return 3;
	}

	// �������� �� ����
	else if (point == 1 || point1 == 1)
	{
		return 2;
	}

	// ����� ��������� �����
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