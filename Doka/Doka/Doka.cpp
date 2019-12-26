#include <iostream>
#include <vector>
#include <windows.h>
#include <Mmsystem.h>
#include <algorithm>
#include <random>
#include <ctime>
#pragma comment(lib, "Winmm.lib")
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
		ID = count++;
		PlayerName = "~~~";
	}
	string PlayerName;
	static int count;
	int rank;
	int ID;
	void	ChangeName(string name) {
		PlayerName = name;
	}
};

int Player::count = 0;

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


auto rng = default_random_engine{};

class PManager {
public:
	vector<Player*> Players;
	PManager() {

	};
	void PlayerCreator() {
		for (int i = 0; i < 10; i++) {
			Player* ReadyPlayerOne = new Player();
			Players.push_back(ReadyPlayerOne);
			Players[i]->PlayerName = PlayerNames[i];
		}
		/*for (int i = 0;i < 10;i++) {
			cout <<endl<<Players[i]->ID << endl
				<< Players[i]->Name << endl
				<< Players[i]->rank << endl;
			Sleep(1200);
		}*/
	}
	void AddPlayer() {
		Player* ReadyPlayerOne = new Player();
		Players.push_back(ReadyPlayerOne);
		int i = Players.size();
		Players[i]->ID = i;
		cout << "######################" << endl
			<< "# Input your Name:";
		cin >> Players[i]->PlayerName;
		cout << "######################" << endl;
	}
	void RemovePlayer(int ID) {
		Players.erase(Players.begin() + ID);
	}
};

class HManager {
public:
	vector<Hero*> Heroes;
	HManager() {

	};
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
	void AddHero() {
		Hero* MightyHero = new Hero();
		Heroes.push_back(MightyHero);
		int i = Heroes.size();
		cout << "######################" << endl
			<< "# Input new Hero Name:";
		cin >> Heroes[i]->Name;
		cout << "######################" << endl
			<< "# Input your HP:";
		cin >> Heroes[i]->HP;
		cout << "######################" << endl
			<< "# Input your DMG:";
		cin >> Heroes[i]->Damage;
		cout << "######################" << endl;
	}
	void RemoveHero(int ID) {
		Heroes.erase(Heroes.begin() + ID);
	}
};


 


//class TeamPart {
//public:
//	TeamPart() {
//		//Creator();
//	};
//	void Creator() {
//		vector<TeamPart*> team;
//		shuffle(begin(Heroes), end(Heroes), rng);
//		for (int i = 0; i < 10; i++) {
//			team.push_back(Players[i]);
//		}
//		for (int j = 0; j < 10;j++) {
//			team.push_back(Heroes[j]);
//		}
//	}
//	Player player;
//	Hero hero;
//};



void PrintInfo() {

}



class TeamPart:Player,Hero {
public:
	TeamPart(Player player, Hero hero) {
		this-> hero = hero;
		this-> player = player;
	}
	Player player;
	Hero hero;
};


class Session {
public:
	vector<TeamPart*> Lobby;
	Session() {
	};
	vector<TeamPart*> TeamRed;
	vector<TeamPart*> TeamBlue;
	/*void Queue(vector<Player>& Players, vector<Hero>& Heroes) {
		shuffle(begin(Heroes), end(Heroes), rng);
		for (int i = 0;i < 5;i++) {
			Player player = Players[i];
			Hero hero = Heroes[i];
			TeamPart* NewPlayer = new TeamPart(player, hero);
			Lobby.push_back(NewPlayer);
		};
	};*/
	void TeamCreator(vector<Player>& Players, vector<Hero>& Heroes) {

		int i=0;
		shuffle(begin(Heroes), end(Heroes), rng);
		while (1) {

			Player player = Players[i];
			Hero hero = Heroes[i];
			TeamPart* NewPlayer = new TeamPart(player, hero);
			srand(time(0));
			int CheckRed = 0;
			int CheckBlue = 0;
			for (int i = 0;i < 5;i++) {
				Player player = Players[i];
				Hero hero = Heroes[i];
				TeamPart* NewPlayer = new TeamPart(player, hero);
				TeamRed.push_back(NewPlayer);
				CheckRed+=TeamRed[i]->player.rank;
			
			};
			for (int i = 5;i < 10;i++) {
				Player player = Players[i];
				Hero hero = Heroes[i];
				TeamPart* NewPlayer = new TeamPart(player, hero);
				TeamBlue.push_back(NewPlayer);
				CheckBlue += TeamBlue[i]->player.rank;
			};
			if(CheckBlue<CheckBlue)
			i++;
		}
	}
};

int main()
{
	PlaySound(TEXT("C:\\Users\\LAPTOP\\Documents\\GIT\\Doka2-trade\\Doka\\Sound.wav"), NULL, SND_ASYNC);
	cout << "Hello World!\n";	
	cout << endl;
	system("pause");	
}