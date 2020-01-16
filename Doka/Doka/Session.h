#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "TeamPart.h"
#include <chrono>
#include <ctime>
using namespace std;
auto rng = default_random_engine{};

class Session {
public:

    vector<TeamPart> lobby;
    vector<TeamPart> TeamRed;
    vector<TeamPart> TeamBlue;


    void Lobby(vector<Player>& Players, vector<Hero>& Heroes) {
        for (int i = 0;i < 10;i++) {
            TeamPart NewPlayer = TeamPart(Players[i], Heroes[i]);
            lobby.push_back(NewPlayer);
        }

    }


    void TeamCreator(vector<Player>& Players, vector<Hero>& Heroes) {

        int z = -1;
        shuffle(begin(Heroes), end(Heroes), rng);
        shuffle(begin(Players), end(Players), rng);
        auto start = std::chrono::system_clock::now();
        time_t start_time = std::chrono::system_clock::to_time_t(start);
        while (z < 0) {
            z++;
            srand(time(0));

            int CheckRed = 0;
            int CheckBlue = 0;
            int RedValid_0 = 0, BlueValid_0 = 0;
            int RedValid_1 = 999999, BlueValid_1 = 999999;

            for (int i = 0;i < 5;i++) {

                TeamPart NewPlayer = TeamPart(Players[i], Heroes[i]);
                TeamRed.push_back(NewPlayer);
                CheckRed += TeamRed[i].player.rank;
                if (RedValid_0 < TeamRed[i].player.rank)
                    RedValid_0 = TeamRed[i].player.rank;
                if (RedValid_0 > TeamRed[i].player.rank)
                    RedValid_0 = TeamRed[i].player.rank;

            };
            for (int i = 0, b = 5;i < 5;i++, b++) {
                TeamPart NewPlayer = TeamPart(Players[b], Heroes[b]);
                TeamBlue.push_back(NewPlayer);
                CheckBlue += TeamBlue[i].player.rank;
                if (BlueValid_0 < TeamBlue[i].player.rank)
                    BlueValid_0 = TeamBlue[i].player.rank;
                if (BlueValid_1 > TeamBlue[i].player.rank)
                    BlueValid_1 = TeamBlue[i].player.rank;
            };

            int teamvalid_0 = 0, teamvalid_B = 0, teamvalid_R = 0;
            teamvalid_0 = CheckBlue - CheckRed;
            teamvalid_B = BlueValid_0 - BlueValid_1;
            teamvalid_R = RedValid_0 - RedValid_1;

            if (teamvalid_0 <= 200 || teamvalid_B <= 100 || teamvalid_R <= 100)
                break;
            else
                shuffle(begin(Players), end(Players), rng);
        }
    }


    void GameManager(vector<TeamPart>& TeamBlue, vector<TeamPart>& TeamRed, vector<Player>& Players, vector<Hero>& Heroes) {
        int RedDmg = 0, BlueDmg = 0, RedHP = 0, BlueHP = 0, red = 0, blue = 0;
        string winner;
        for (int i = 0; i < 5; i++) {
            RedDmg += TeamRed[i].hero.Damage;
            RedHP += TeamRed[i].hero.HP;
            BlueDmg += TeamBlue[i].hero.Damage;
            BlueHP += TeamBlue[i].hero.HP;
        }
        red = RedHP - BlueDmg;
        blue = BlueHP - RedDmg;

        if (red > blue) {
            winner = "Red won";
            for (int i = 0; i < 5;i++) {
                int IDred = TeamBlue[i].player.ID;
                int IDblue = TeamRed[i].player.ID;
                for (int i = 0; i < 10;i++) {
                    if (IDred == Players[i].ID) {
                        Players[i].rank += 25;
                    }
                    if (IDblue == Players[i].ID) {
                        Players[i].rank -= 25;
                    }
                }
            }
        }
        else if (red < blue) {
            winner = "Blue won";
            for (int i = 0; i < 5;i++) {
                int IDred = TeamBlue[i].player.ID;
                int IDblue = TeamRed[i].player.ID;
                for (int i = 0; i < 10;i++) {
                    if (IDred == Players[i].ID) {
                        Players[i].rank -= 25;
                    }
                    if (IDblue == Players[i].ID) {
                        Players[i].rank += 25;
                    }
                }
            }
        }
        else
            winner = "Tie";

        auto end = std::chrono::system_clock::now();
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        ofstream Log;

        Log.open("BattleLog.txt", ios::app);
        Log << "blue Player\tblue Hero\n";
        for (int i = 0; i < 5;i++) {
            Log << "   " << TeamBlue[i].player.PlayerName << " rank " << TeamBlue[i].player.rank << "\t" << TeamBlue[i].hero.Name << endl;
        }
        Log << "red Player \t red Hero\n";
        for (int i = 0; i < 5;i++) {
            Log << "   " << TeamRed[i].player.PlayerName << " rank " << TeamRed[i].player.rank << "\t" << TeamRed[i].hero.Name << endl;
        }
        Log << "info:\n" << "Blue dmg: " << RedDmg << "\nRed dmg: " << BlueDmg << endl;
        Log << "winner! - " << winner << endl;

        Log /*<< "finished Battle at " << std::ctime(&start_time)*/
            << "finished Battle at " << std::ctime(&end_time)
            << endl;

        Log << "-------------\n";
        Log.close();

    }


    Session() {

    };
};