#include <iostream>
#include <windows.h>
#include <ctime>
#include "Cards.h"
#include "Croupier.h"
#include "Player.h"

using namespace std;

int main()
{
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Cards> card1;
    Player pl1 = Player("Daniel", 1000);
    Player pl2 = Player("Denis", 1000);
    Croupier c1 = Croupier();
    c1.setDeckCr();
    card1 = c1.getRandCard();
    pl1.setDeck(card1);
    card1 = c1.getRandCard();
    pl2.setDeck(card1);

    pl1.getDeck();

    c1.checkCombination(pl1.getDeck(), c1.getDeckCr(), 1);
}