#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <Mmsystem.h>
#include <algorithm>
#include <random>
#include <ctime>
#pragma comment(lib, "Winmm.lib")
#include "Player.h"
#include "Hero.h"
#include "PManager.h"
#include "HManager.h"
#include "TeamPart.h"
#include "Session.h"
#include "SManager.h"
using namespace std;

const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;

void clearScreen(int characterLength) {
    for (int i = 0; i < characterLength; i++) {
        cout << "\b";
    }
}

void changeColour(int colour) {
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
}

void showLoadingScreen() {
    int i;
    string closed = "- - -", open = "* * *";
    int colour[] = { RED, GREEN, BLUE };

    cout << closed;

    for (i = 0; i < 3; i++) {
        Sleep(1000);

        clearScreen(5);
        changeColour(colour[i]);

        cout << open;

        Sleep(1000);

        clearScreen(5);
        changeColour(WHITE);

        cout << closed;
    }

    clearScreen(5);
    changeColour(WHITE);
}

void PerformGame(int num,int check) {
    SManager game;
    PManager player;
    HManager hero;
    player.PlayerCreator();
    hero.HeroesCreator();
    switch (check)
    {
    case 1:
        game.PerformSession(player.Players, hero.Heroes, num);
        break;
    case 2:
        player.AddPlayer();
        break;
    case 3:
        hero.AddHero();
        break;
    default:
        break;
    }
    
}

bool menu() {
    cout << "Hello!" << endl;
    cout << "what do you want?"<<endl;
    cout<<"1. play\n2. create new player\n3. create new hero\n4. quit"<<endl;
    int switch_on;
    cin >> switch_on;
    bool quit = 0;
    switch (switch_on)
    {
    case 1:
        cout << "how much games?\n";
        int i;
        cin >> i;
        PerformGame(i,1);
        break;
    case 2:
        PerformGame(0, 2);
        break;
    case 3:
        PerformGame(0, 3);
        break;
    case 4:
        quit = 1;
        break;
    default:
        break;
    }
    return quit;
}

int main()
{
    showLoadingScreen();
    PlaySound(TEXT("../drown.wav"), NULL, SND_ASYNC);
    while (1) {
        bool quit = menu();
        if (quit == 1)break;
    }
    cout << "Hello World!\n";	
    cout << endl;
    system("pause");	
}