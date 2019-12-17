#include <iostream>
#include <vector>
#include <windows.h>
#include "Clases.h"
using namespace std;

string HeroNames[] = { "kek","maeve","Yuriu","Arthas","Furry","neko","loli","Lich King","Unity","Unreal Engine" };
int HP[] = { 123, 132, 1, 542, 100, 142, 999, 1244, 156, 666 };
int Dmg[] = { 666, 156, 1244, 999, 142, 100, 542, 1, 132, 123 };
string PlayerNames[] = { "Valera","Petro","Yuriu","Jack","Misha","Onhii","Vasul","Ivan","Yana","John" };

class Player {
public:

	Player() {
		rank = 10000;
		ID = 0;
		Name = "~~~";
	}
	string Name;
	int rank;
	int ID;
	void hello() {
		cout << "hello";
	}
};

class Hero {
public:
	Hero() {
		Name = "~~~";
		HP = 0;
		Damage = 0;
		Speed = 0;
	};
	string Name;
	int HP;
	int Damage;
	int Speed;
};

class Session {
public:
	/*TeamPart* TeamRed = new TeamPart[5];
	TeamPart* TeamBlue = new TeamPart[5];*/
	string Winner;
};

class PManager {

};

vector<Player*> Players;
vector<Hero*> Heroes;

void PlayerCreator() {
	for (int i = 0; i < 10; i++) {
		Player* ReadyPlayerOne = new Player();
		Players.push_back(ReadyPlayerOne);
		Players[i]->ID = i;
		Players[i]->Name = PlayerNames[i];
	}
	for (int i = 0;i < 10;i++) {
		cout <<endl<<Players[i]->ID << endl
			<< Players[i]->Name << endl
			<< Players[i]->rank << endl;
		Sleep(1200);
	}
}

 
void HeroesCreator() {
	for (int i = 0; i < 10; i++) {
		Hero* MightyHero = new Hero();
		Heroes.push_back(MightyHero);
		Heroes[i]->Damage = Dmg[i];
		Heroes[i]->HP = HP[i];
		Heroes[i]->Name = HeroNames[i];
		Heroes[i]->Speed = i;
	}

	/*for (int i = 0;i < 10;i++) {
		cout << endl << Heroes[i]->Name << endl
			<< Heroes[i]->HP << endl
			<< Heroes[i]->Damage << endl
			<< Heroes[i]->Speed << endl;
	}*/
}



class TeamPart : Player, Hero {
public:
	TeamPart() {
		/*vector<TeamPart*> team;
		for (int i = 0; i < 10; i++) {
			team[i] = Heroes[i];
			for (int j = 0; j < 10;j++) {
				team[j] = Players[j];
			}
		}*/
	};

};

void PrintInfo() {

}


int main()
{
    cout << "Hello World!\n";
	PlayerCreator();
	cout << endl;
	goto hello;
	HeroesCreator();
hello:
	cout << "kek";
}