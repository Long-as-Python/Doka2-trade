#pragma once
#include <iostream>
using namespace std;

string PlayerNames[] = { "Valera","Petro","Yuriu","Jack","Misha","Onhii","Vasul","Ivan","Yana","John" };

class Player {
public:
    Player() {
        rank = 10000;
        ID = 0;
        PlayerName = "~~~";
    }
    Player(int newrank, int id, string playername) {
        rank = newrank;
        ID = id;
        PlayerName = playername;
    }

    string PlayerName;
    int rank;
    int ID;
    void	ChangeName(string name) {
        PlayerName = name;
    }
};

