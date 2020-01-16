#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Hero.h"
using namespace std;

class PManager {
public:
    vector<Player> Players;
    PManager() {};
    void PlayerCreator() {
        for (int i = 0; i < 10; i++) {
            Player ReadyPlayerOne = Player(10000, i, PlayerNames[i]);
            Players.push_back(ReadyPlayerOne);
        }
    }
    void AddPlayer() {
        string PlayerName;
        int i = Players.size();
        cout << "######################" << endl
            << "# Input your Name:";
        cin >> PlayerName;
        cout << "######################" << endl;
        Player ReadyPlayerOne = Player(10000, i + 1, PlayerName);
        Players.push_back(ReadyPlayerOne);
    }
    void RemovePlayer(int ID) {
        Players.erase(Players.begin() + ID);
    }
};
