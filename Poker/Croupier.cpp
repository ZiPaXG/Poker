#include "Croupier.h"

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

int Croupier::checkCombination(vector<Cards> deck, vector<Cards> deckCr, int a)
{
	// 10 вариантов
	vector<Cards> combo = deck;
	int score;

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

		break;
	}

	return 0;
}
