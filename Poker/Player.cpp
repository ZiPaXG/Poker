#include "Player.h"

void Player::setDeck(vector<Cards>card)
{
	for (int i = 0; i < card.size(); i++)
	{
		deck.push_back(card[i]);
	}
}

void Player::showDeck()
{
	for (int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].getCards() << " ";
	}
	cout << endl;
}

string Player::getNameP()
{
	return name;
}

void Player::setMoney(float _money)
{
	money += _money;
}

void Player::setMoneyMain(float _money)
{
	money = _money;
}

vector<Cards> Player::getDeck()
{
	return deck;
}

void Player::setBet(float a)
{
	money -= a;
	bet += a;
}

float Player::getBet()
{
	return bet;
}

Player Player::Call(Player pl, float allBet)
{
	float a = allBet - pl.bet;
	pl.bet += a;
	pl.money -= a;
	cout << pl.bet << " " << pl.money << endl;
	return pl;
}

Player Player::Raise(Player pl, float allBet)
{
	int count;
	
	cout << "Введите новую ставку: " << endl;
	cin >> count;

	for (;;)
	{
		if (count < allBet)
		{
			cout << "Эта ставка меньше, чем предыдущая! Введите новую ставку: " << endl;
			cin >> count;
		}
		
		else if (count > pl.money)
		{
			cout << "У вас недостаточно денег для такой ставки!" << endl;
		}

		else
		{
			break;
		}
	}

	float count1 = count - pl.bet;
	pl.bet += count1;
	pl.money -= count1;
	cout << pl.bet << " " << pl.money << endl;
	return pl;
}

Player Player::VaBank(Player pl)
{
	pl.bet += pl.money;
	pl.money -= pl.bet;
	cout << pl.bet << " " << pl.money << endl;
	return pl;
}

vector<Player> Player::Fold(vector<Player> players, int i)
{
	players.erase(players.begin() + i);
	return players;
}

float Player::getMoney()
{
	return money;
}

vector<Player> Player::clearBet(vector<Player> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		players[i].bet = 0;
	}

	return players;
}

void Player::clearCards(Player player1)
{
	deck.clear();
}

//void Player::setDeckPl()
//{
//	deck.push_back(Cards(4, 1));
//	deck.push_back(Cards(4, 3));
//}
