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
    vector<int> moneyPl;
    string name;
    float money;
    int counter;
    int check = 0;
    int bet = 0; // ставка
    vector<Player> players; // здесь не будет тех, кто сбросил карты
    vector<Player> playersMain; //здесь будут все игроки
    int score1 = 0;
    int n; // кол-во игроков
    vector<Cards> card1;
    Croupier c1;
    for (;;)
    {
        cout << "Введите, сколько игроков будет играть: " << endl;
        cin >> n;
        if (n < 2 || n > 10)
        {
            cout << "Столько игроков быть не может! " << endl;
        }
        
        else
        {
            break;
        }
    }

    cin.get();

    system("cls");

    // создаем игроков и раздаем карты
    for (int i = 0; i < n; i++)
    {
        cout << "Введите имя " << i + 1 << " игрока: " << endl;
        getline(cin, name);
        
        score.push_back(0);
        cout << "Введите кол-во денег: " << endl;
        cin >> money;
        cin.get();
        playersMain.push_back(Player(name, money));
    }

    system("cls");

    for (;;)
    {
        for (int i = 0; i < playersMain.size(); i++)
        {
            if (playersMain[i].getMoney() <= 0)
            {
                cout << "Игрок " << playersMain[i].getNameP() << " выбыает из-зи нехватки денег!" << endl;
                playersMain.erase(playersMain.begin() + i);
                n--;
            }
        }

        if (playersMain.size() == 1)
        {   
            system("cls");
            cout << "Остался один игрок! Т.к. игроков больше нет, то игра остановится!" << endl;
            cout << "Спасибо за игру! Удачи!" << endl;
            break;
        }

        c1 = Croupier();
        for (int i = 0; i < n; i++)
        {
            card1 = c1.getRandCard();
            playersMain[i].setDeck(card1);
        }
        c1.setDeckCr();
        players = playersMain;

        // делают ставки
        players = c1.SetBet1(players, n, bet);
        for (int i = 0; i < players.size(); i++)
        {
            playersMain[i].setMoneyMain(players[i].getMoney());
        }
        c1.setBank(players);

        Sleep(5000);
        system("cls");

        c1.clearAllBet();

        // сама игра (флоп)
        for (int i = 0; i < players.size(); i++)
        {
            cout << "Колода крупье: " << endl;
            c1.showDeck(c1.getDeckCr(), 3);
            cout << "Колода игрока: " << endl;
            players[i].showDeck();
            vector<Cards> combo = players[i].getDeck();
            score[i] = c1.ComboCard(combo, c1.getDeckCr(), 1);
            c1.showCombination(score[i]);

            cout << endl;
            system("pause");
            system("cls");
        }

        if (players.size() == 1)
        {
            playersMain = c1.getWin(score, players, c1, playersMain);
            for (;;)
            {
                cout << "Если хотите продолжить играть - введите 1, если хотите остановиться - введите 2: " << endl;
                cin >> check;

                if (check < 1 || check > 2)
                {
                    cout << "Такого варианта нет!!! " << endl;
                }

                else
                    break;
            }

            if (check == 2)
                break;
            else
            {
                c1.setMainAllBet();
                c1.newCards();
                for (int i = 0; i < n; i++)
                {
                    playersMain[i].clearCards(playersMain[i]);
                }
            }
        }

        else
        {
            // очистка ставок игроков
            for (int i = 0; i < players.size(); i++)
            {
                players = players[i].clearBet(players);
            }

            players = c1.SetBet2(players, n, bet);
            for (int i = 0; i < players.size(); i++)
            {
                playersMain[i].setMoneyMain(players[i].getMoney());
            }
            c1.setBank(players);

            Sleep(5000);
            system("cls");

            c1.clearAllBet();

            // 2 фаза игры (терн)
            for (int i = 0; i < players.size(); i++)
            {
                cout << "Колода крупье: " << endl;
                c1.showDeck(c1.getDeckCr(), 4);
                cout << "Колода игрока " << players[i].getNameP() << ": " << endl;
                players[i].showDeck();
                vector<Cards> combo = players[i].getDeck();
                score1 = c1.ComboCard(combo, c1.getDeckCr(), 2);
                if (score1 > score[i])
                {
                    score[i] = score1;
                }
                c1.showCombination(score[i]);

                cout << endl;
                system("pause");
                system("cls");
            }

            if (players.size() == 1)
            {
                playersMain = c1.getWin(score, players, c1, playersMain);
                for (;;)
                {
                    cout << "Если хотите продолжить играть - введите 1, если хотите остановиться - введите 2: " << endl;
                    cin >> check;

                    if (check < 1 || check > 2)
                    {
                        cout << "Такого варианта нет!!! " << endl;
                    }

                    else
                        break;
                }
                if (check == 2)
                    break;
                else
                {
                    c1.setMainAllBet();
                    c1.newCards();
                    for (int i = 0; i < n; i++)
                    {
                        playersMain[i].clearCards(playersMain[i]);
                    }
                }
            }

            else
            {
                // очистка ставок игроков
                for (int i = 0; i < players.size(); i++)
                {
                    players = players[i].clearBet(players);
                }

                players = c1.SetBet2(players, n, bet);
                for (int i = 0; i < players.size(); i++)
                {
                    playersMain[i].setMoneyMain(players[i].getMoney());
                }
                c1.setBank(players);

                Sleep(5000);
                system("cls");

                c1.clearAllBet();

                // 3 фаза игры (ривер)
                for (int i = 0; i < players.size(); i++)
                {
                    cout << "Колода крупье: " << endl;
                    c1.showDeck(c1.getDeckCr(), 5);
                    cout << "Колода игрока: " << endl;
                    players[i].showDeck();
                    vector<Cards> combo = players[i].getDeck();
                    score1 = c1.ComboCard(combo, c1.getDeckCr(), 3);
                    if (score1 > score[i])
                    {
                        score[i] = score1;
                    }
                    c1.showCombination(score[i]);

                    cout << endl;
                    system("pause");
                    system("cls");
                }

                playersMain = c1.getWin(score, players, c1, playersMain);
                for (;;)
                {
                    cout << "Если хотите продолжить играть - введите 1, если хотите остановиться - введите 2: " << endl;
                    cin >> check;

                    if (check < 1 || check > 2)
                    {
                        cout << "Такого варианта нет!!! " << endl;
                    }

                    else
                        break;
                }
                if (check == 2)
                    break;

                else
                {
                    c1.setMainAllBet();
                    c1.newCards();
                    for (int i = 0; i < n; i++)
                    {
                        playersMain[i].clearCards(playersMain[i]);
                    }
                }
            }
        }
    }
}