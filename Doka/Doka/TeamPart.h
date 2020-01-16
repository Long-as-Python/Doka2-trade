#pragma once
#include "Player.h"
#include "Hero.h"
class TeamPart :Player, Hero {
public:

    Player player;
    Hero hero;

    TeamPart(Player& player, Hero& hero) {
        this->hero = hero;
        this->player = player;
    }
};

