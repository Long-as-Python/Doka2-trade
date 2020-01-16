#pragma once
#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;

string HeroNames[] = { "kek","maeve","Yuriu","Arthas","Furry","neko","loli","Lich King","Unity","Unreal Engine" };
int HP[] = { 123, 132, 1, 542, 100, 142, 999, 1244, 156, 666 };
int Dmg[] = { 666, 156, 1244, 999, 142, 100, 542, 1, 132, 123 };

class HManager {
public:
    vector<Hero> Heroes;
    HManager() {

    };
    void HeroesCreator() {
        for (int i = 0; i < 10; i++) {
            Hero MightyHero = Hero(HeroNames[i], HP[i], Dmg[i], i);
            Heroes.push_back(MightyHero);
        }
    }
    void AddHero() {
        int i = Heroes.size();
        cout << "######################" << endl
            << "# Input new Hero Name:";
        string Name;
        cin >> Name;
        cout << "######################" << endl
            << "# Input your HP:";
        int HP;
        cin >> HP;
        cout << "######################" << endl
            << "# Input your DMG:";
        int Damage;
        cin >> Damage;
        cout << "######################" << endl;
        Hero MightyHero = Hero(Name, HP, Damage, 1);
        Heroes.push_back(MightyHero);
    }
    void RemoveHero(int ID) {
        Heroes.erase(Heroes.begin() + ID);
    }
};
