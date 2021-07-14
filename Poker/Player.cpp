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

vector<Cards> Player::getDeck()
{
	return deck;
}

void Player::setBet(int a)
{
	money -= a;
	bet += a;
}
