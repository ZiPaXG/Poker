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
		mas.erase(mas.begin() + n1);
	}
}

vector<Cards> Croupier::getDeckCr()
{
	return deckCr;
}

void Croupier::showDeck(vector<Cards> v1, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << v1[i].getCards() << " ";
	}
	cout << endl;
}

int Croupier::ComboCard(vector<Cards> combo, vector<Cards> deckCr, int a)
{
	Cards temp = Cards(1, 1);
	Cards temp1 = Cards(1, 1);
	
	int score = 0, score1 = 0;
	
	switch (a)
	{
	case 1:
	{
		combo.insert(combo.end(), deckCr.begin(), deckCr.end() - 2);

		// сортировка пузырьком
		for (int i = 0; i < combo.size() - 1; i++)
		{
			for (int j = 0; j < combo.size() - i - 1; j++)
			{
				if (combo[j].getName() > combo[j + 1].getName())
				{
					iter_swap(combo.begin() + j, combo.begin() + j + 1);
				}
			}
		}
		score = checkCombination(combo);
	}
	break;
		
	case 2:
	{
		vector <Cards> combo1;
		combo.insert(combo.end(), deckCr.begin(), deckCr.end() - 2);
		Cards card = Cards(deckCr[3].getName(), deckCr[3].getSuits());
		combo1 = combo;
		for (int j = 0; j < 5; j++)
		{
			// смотрим все варианты комбинаций
			temp = combo[j];
			combo[j] = card;
			
			// сортировка пузырьком
			for (int i = 0; i < combo.size() - 1; i++)
			{
				for (int j = 0; j < combo.size() - i - 1; j++)
				{
					if (combo[j].getName() > combo[j + 1].getName())
					{
						iter_swap(combo.begin() + j, combo.begin() + j + 1);
					}
				}
			}
			
			// проверка на комбинацию
			score1 = checkCombination(combo);
			if (score < score1)
			{
				score = score1;
			}

			combo[j] = temp;
			combo = combo1;
		}
	}
	break;
	
	case 3:
	{
		vector <Cards> combo1;
		combo.insert(combo.end(), deckCr.begin(), deckCr.end() - 2);
		Cards card1 = Cards(deckCr[3].getName(), deckCr[3].getSuits());
		Cards card2 = Cards(deckCr[4].getName(), deckCr[4].getSuits());
		combo1 = combo;

		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				// смотрим все варианты комбинаций
				temp = combo[j];
				combo[j] = card1;

				temp1 = combo[i];
				combo[i] = card2;
				// сортировка пузырьком
				for (int i = 0; i < combo.size() - 1; i++)
				{
					for (int j = 0; j < combo.size() - i - 1; j++)
					{
						if (combo[j].getName() > combo[j + 1].getName())
						{
							iter_swap(combo.begin() + j, combo.begin() + j + 1);
						}
					}
				}

				// проверка на комбинацию
				score1 = checkCombination(combo);
				if (score < score1)
				{
					score = score1;
				}

				combo[j] = temp;

				combo[i] = temp1;

				combo = combo1;
			}
		}
	}
	break;
	}
	
	return score;
}

int Croupier::checkCombination(vector<Cards> combo)
{
	// 10 вариантов
	int score = 0;

	//showDeck(combo);
	score = RoyalFlash(combo);

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
	int point2 = 0;
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

	// проверка на обычный стрит
	for (int i = 0; i < 1; i++)
	{
		for (int j = i + 1; j < combo.size(); j++)
		{
			if (combo[i].getName() == combo[j].getName() - j)
			{
				point2++;
			}
		}
	}

	// проверка на сам роял флеш
	if (point == 5 && point1 == 4)
	{
		return 10;
	}

	//возвращает "королевский" стрит
	else if (point == 5 && point1 != 4)
	{
		return 5;
	}

	else if (point != 5 && point1 == 4 && point2 == 4)
	{
		return 9;
	}

	else if (point != 5 && point1 == 4 && point2 != 4)
	{
		return 6;
	}

	else if (point != 5 && point1 != 4 && point2 == 4)
	{
		return 5;
	}

	// если нет совпадений
	else
	{
		t =  Care(combo);
		return t;
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

	// поиск наивысшей карты
	else if (point[combo.size() - 1] == 0)
	{
		return 1;
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

	// проверка на две пары
	if (point == point1)
	{
		return 3;
	}

	// проверка на пару
	else if (point == 1 || point1 == 1)
	{
		return 2;
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

	return point;
}

void Croupier::setBank(vector<Player> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		bank += players[i].getBet();
	}

}

float Croupier::getBank()
{
	return bank;
}

void Croupier::setAllBet(vector<Player> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getBet() > allBet)
		{
			allBet = players[i].getBet();
		}
	}
}

void Croupier::clearAllBet()
{
	allBet = 0;
}

float Croupier::getAllBet()
{
	return allBet;
}

vector<Player> Croupier::SetBet1(vector<Player> players, int n, int bet)
{
	for (;;)
	{
		int counter = 0;
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].getMoney() != 0)
			{
				cout << "На кону: " << getBank() << endl;
				cout << "Ставка: " << getAllBet() << endl;
				cout << players[i].getNameP() << " игрок - введите 1 - Колл, введите 2 - Рейз " << endl;
				cout << "введите 3 - Ва-банк, введите 4 - Фолд (сброс карт): " << endl;
				cin >> bet;

				switch (bet)
				{
				case 1:
				{
					if (players[i].getMoney() > getAllBet())
					{
						players[i] = players[i].Call(players[i], getAllBet());
						setAllBet(players);
					}

					else
					{
						cout << "У вас недостаточно денег для коллирования! Вы идёте Ва-банк! " << endl;
						players[i] = players[i].VaBank(players[i]);
					}
				}
				break;

				case 2:
				{
					if (players[i].getMoney() > getAllBet())
					{
						players[i] = players[i].Raise(players[i], getAllBet());
						setAllBet(players);
					}

					else
					{
						cout << "У вас недостаточно денег для повышения ставки! Введите 1 - Колл, введите 2 - Ва-банк: " << endl;
						cin >> bet;
						if (bet == 1)
						{
							players[i] = players[i].Call(players[i], getAllBet());
							setAllBet(players);
						}

						else if (bet == 2)
						{
							players[i] = players[i].VaBank(players[i]);
							setAllBet(players);
						}
					}
				}
				break;

				case 3:
				{
					players[i] = players[i].VaBank(players[i]);
					setAllBet(players);
				}
				break;

				case 4:
				{
					players = players[i].Fold(players, i);
					i -= 1;
				}
				break;
				}
				cout << endl;
			}

			else
			{
				cout << "Игрок " << players[i].getNameP() << ", у вас нету денег для ставок" << endl;
			}
			
		}
		for (int i = 0; i < players.size() - 1; i++)
		{
			if (players[i].getBet() == players[i + 1].getBet())
			{
				counter++;
			}
		}

		if (counter == players.size() - 1)
			break;
	}
	return players;
}

vector<Player> Croupier::SetBet2(vector<Player> players, int n, int bet)
{
	for (;;)
	{
		int counter = 0;
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].getMoney() != 0)
			{
				cout << "На кону: " << getBank() << endl;
				cout << "Ставка: " << getAllBet() << endl;
				cout << players[i].getNameP() << " игрок - введите 1 - Колл/Чек, введите 2 - Рейз " << endl;
				cout << "введите 3 - Ва-банк, введите 4 - Фолд (сброс карт): " << endl;
				cin >> bet;
				switch (bet)
				{
				case 1:
				{
					if (players[i].getMoney() > getAllBet())
					{
						players[i] = players[i].Call(players[i], getAllBet());
						setAllBet(players);
					}

					else
					{
						cout << "У вас недостаточно денег для коллирования! Вы идёте Ва-банк! " << endl;
						players[i] = players[i].VaBank(players[i]);
					}
				}
				break;

				case 2:
				{
					if (players[i].getMoney() > getAllBet())
					{
						players[i] = players[i].Raise(players[i], getAllBet());
						setAllBet(players);
					}

					else
					{
						cout << "У вас недостаточно денег для повышения ставки! Введите 1 - Колл, введите 2 - Ва-банк: " << endl;
						cin >> bet;
						if (bet == 1)
						{
							players[i] = players[i].Call(players[i], getAllBet());
							setAllBet(players);
						}

						else if (bet == 2)
						{
							players[i] = players[i].VaBank(players[i]);
							setAllBet(players);
						}
					}
				}
				break;

				case 3:
				{
					players[i] = players[i].VaBank(players[i]);
					setAllBet(players);
				}
				break;

				case 4:
				{
					players = players[i].Fold(players, i);
					i -= 1;
				}
				break;
				}

				cout << endl;
			}
			
			else
			{
				cout << "Игрок " << players[i].getNameP() << ", у вас нету денег для ставок" << endl;
			}
		}

		for (int i = 0; i < players.size() - 1; i++)
		{
			if (players[i].getBet() == players[i + 1].getBet())
			{
				counter++;
			}
		}

		if (counter == players.size() - 1)
			break;
	}
	return players;
}

vector<Player> Croupier::getWin(vector<int> score, vector <Player> players, Croupier c1, vector<Player> playersMain)
{
	int win = 0;
	int winid = 0;
	int check = 0;
	vector<int> id;

	if (players.size() == 1)
	{
		cout << "Победил " << players[0].getNameP() << "!!!" << endl;
		players[0].setMoney(getBank());
		bank = 0;
		cout << "Ваш счёт: " << players[0].getMoney() << endl;
		playersMain[0].setMoneyMain(players[0].getMoney());
		
		return playersMain;
	}

	for (int i = 0; i < score.size(); i++)
	{
		if (win < score[i])
		{
			if (!id.empty())
			{
				id.clear();
			}

			win = score[i];
			winid = i;
			id.push_back(winid);
		}
		
		else if (win == score[i])
		{
			id.push_back(i);
		}
	}

	if (!id.empty())
	{
		if (win > score[id[0]])
		{
			cout << "Победил " << players[winid].getNameP() << "!!!" << endl;
			players[winid].setMoney(getBank());
			bank = 0;
			cout << "Ваш счёт: " << players[winid].getMoney() << endl;
			cout << endl;
			playersMain[winid].setMoneyMain(players[winid].getMoney());

			return playersMain;
		}

		else
		{
			id = getDraw(score, players, id, c1.getDeckCr());
			
			if (id.size() > 1)
			{
				bank /= id.size();
				for (int i = 0; i < id.size(); i++)
				{
					players[id[i]].setMoney(bank);
					playersMain[id[i]].setMoneyMain(players[id[i]].getMoney());
				}
				bank = 0;

				cout << "Победили игроки: " << endl;
				for (int j = 0; j < id.size(); j++)
				{
					cout << "Игрок " << players[id[j]].getNameP() << endl;
					cout << "Баланс: " << players[id[j]].getMoney() << endl;
				}

				return playersMain;
			}

			else
			{
				cout << "Победил " << players[id[0]].getNameP() << "!!!" << endl;
				players[id[0]].setMoney(getBank());
				bank = 0;
				cout << "Ваш счёт: " << players[id[0]].getMoney() << endl;
				playersMain[id[0]].setMoneyMain(players[id[0]].getMoney());

				return playersMain;
			}
		}
	}

	else
	{
		cout << "Победил " << players[winid].getNameP() << "!!!" << endl;
		players[winid].setMoney(getBank());
		bank = 0;
		cout << "Ваш счёт: " << players[winid].getMoney() << endl;
		playersMain[winid].setMoneyMain(players[winid].getMoney());

		return playersMain;
	}
}

vector<int> Croupier::getDraw(vector<int> score, vector<Player> players, vector <int> id, vector<Cards> deckCr)
{
	vector<Cards> cd;
	vector<Cards> cd1;
	int high = 0;
	int high1 = 0;
	int n = 0;
	vector<int> highid;
	vector<int> dubl;

	if (score[id[0]] > 4)
	{
		return id;
	}

	else
	{
		for (int f = 0; f < id.size()-1; f++)
		{
			cd = players[id[f]].getDeck();
			cd1 = players[id[f + 1]].getDeck();
			cd.insert(cd.end(), deckCr.begin(), deckCr.end());
			cd1.insert(cd1.end(), deckCr.begin(), deckCr.end());

			for (int i = 0; i < cd.size() - 1; i++)
			{
				for (int j = 0; j < cd.size() - i - 1; j++)
				{
					if (cd[j].getName() < cd[j + 1].getName())
					{
						iter_swap(cd.begin() + j, cd.begin() + j + 1);
					}
				}
			}

			for (int i = 0; i < cd1.size() - 1; i++)
			{
				for (int j = 0; j < cd1.size() - i - 1; j++)
				{
					if (cd1[j].getName() < cd1[j + 1].getName())
					{
						iter_swap(cd1.begin() + j, cd1.begin() + j + 1);
					}
				}
			}

			for (int j = 0; j < cd.size(); j++)
			{
				if (cd[j].getName() < cd1[j].getName())
				{
					if (!dubl.empty())
					{
						id.erase(id.begin() + dubl[0]);
						id.erase(id.begin() + dubl[1]);

						dubl.clear();
					}

					id.erase(id.begin() + f);
					j += cd.size() - 1 - j;
					cout << endl;
					f--;
				}

				else if (cd[j].getName() > cd1[j].getName())
				{
					id.erase(id.begin() + f + 1);
					j += cd.size() - 1 - j;
					cout << endl;
					f--;
				}

				else if (cd[j].getName() == cd1[j].getName() && j == cd.size() - 1)
				{
					//cout << "3 " << cd[j].getCards() << " " << cd1[j].getCards() << endl;
					dubl.push_back(f);
					dubl.push_back(f + 1);
				}

			}
		}

	}

	return id;
}

void Croupier::setMainAllBet()
{
	allBet = 50;
}

void Croupier::newCards()
{
	mas.clear();
}

//void Croupier::setDeck()
//{
//	deckCr.push_back(Cards(4, 2));
//	deckCr.push_back(Cards(4, 3));
//	deckCr.push_back(Cards(6, 2));
//	deckCr.push_back(Cards(13, 3));
//	deckCr.push_back(Cards(14, 3));
//}