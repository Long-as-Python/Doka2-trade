#pragma once
#include <iostream>
using namespace std;

class Hero {
public:
    Hero() {
        Name = "~~~";
        HP = 0;
        Damage = 0;
        Speed = 0;
    };
    Hero(string newname, int newhp, int newdmg, int speed) {
        Name = newname;
        HP = newhp;
        Damage = newdmg;
        Speed = 1;
    }
    string Name;
    int HP;
    int Damage;
    int Speed;
};
