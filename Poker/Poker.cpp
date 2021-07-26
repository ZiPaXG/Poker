#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include "Cards.h"
#include "Croupier.h"
#include "Player.h"
#include <conio.h>

using namespace std;

int main()
{
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    vector<int> score = {}; //переменная, которая показывает насколько мощная комбинация
    vector<int> point = {}; // если score == 1 - сюда записываем номер высокой карты
    string name;
    float money;
    int counter;
    float bet = 0; // ставка
    vector<Player> players;
    int score1 = 0;
    int n; // кол-во игроков
    vector<Cards> card1;

    Croupier c1 = Croupier();
    cout << "Введите, сколько игроков будет играть: " << endl;
    cin >> n;
    cin.get();

    c1.setDeckCr();

    // создаем игроков и раздаем карты
    for (int i = 0; i < n; i++)
    {
        cout << "Введите имя " << i + 1 << " игрока: " << endl;
        getline(cin, name);
        
        score.push_back(0);
        cout << "Введите кол-во денег: " << endl;
        cin >> money;
        cin.get();
        point.push_back(0);
        players.push_back(Player(name, money));
        card1 = c1.getRandCard();
        players[i].setDeck(card1);
    }

    // делают ставки
    players = c1.SetBet1(players, n, bet);

    c1.setBank(players);

    Sleep(5000);
    system("cls");

    c1.clearAllBet();

    // сама игра (флоп)
    for (int i = 0; i < n; i++)
    {
        cout << "Колода крупье: " << endl;
        c1.showDeck(c1.getDeckCr(), 3);
        cout << "Колода игрока: " << endl;
        players[i].showDeck();
        vector<Cards> combo = players[i].getDeck();
        score[i] = c1.ComboCard(combo, c1.getDeckCr(), 1);
        c1.showCombination(score[i]);

        if (score[i] == 1)
        {
            point.push_back(c1.HighCard(combo));
        }
        
        cout << endl;
        system("pause");
        system("cls");
    }

    // очистка ставок игроков
    for (int i = 0; i < n; i++)
    {
        players = players[i].clearBet(players);
    }

    players = c1.SetBet2(players, n, bet);
    c1.setBank(players);    
    
    Sleep(5000);
    system("cls");

    // 2 фаза игры (терн)
    for (int i = 0; i < n; i++)
    {
        cout << "Колода крупье: " << endl;
        c1.showDeck(c1.getDeckCr(), 4);
        cout << "Колода игрока: " << endl;
        players[i].showDeck();
        vector<Cards> combo = players[i].getDeck();
        score[i] = c1.ComboCard(combo, c1.getDeckCr(), 2);
        c1.showCombination(score[i]);

        if (score[i] == 1)
        {
            point.push_back(c1.HighCard(combo));
        }

        cout << endl;
        system("pause");
        system("cls");
    }

    // очистка ставок игроков
    for (int i = 0; i < n; i++)
    {
        players = players[i].clearBet(players);
    }

    players = c1.SetBet2(players, n, bet);
    c1.setBank(players);
    
    Sleep(5000);
    system("cls");

    // 3 фаза игры (ривер)
    for (int i = 0; i < n; i++)
    {
        cout << "Колода крупье: " << endl;
        c1.showDeck(c1.getDeckCr(), 5);
        cout << "Колода игрока: " << endl;
        players[i].showDeck();
        vector<Cards> combo = players[i].getDeck();
        score[i] = c1.ComboCard(combo, c1.getDeckCr(), 3);
        c1.showCombination(score[i]);

        if (score[i] == 1)
        {
            point.push_back(c1.HighCard(combo));
        }

        cout << endl;
        system("pause");
        system("cls");
    }

    // подведение итогов
    for (int i = 0; i < score.size(); i++)
    {
        cout << point[i] << endl;
    }
    
    c1.getWin(score, point, players);
}