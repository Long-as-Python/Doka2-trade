#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "Session.h"
#include <chrono>
#include <ctime>
using namespace std;
class SManager {
public:
    void PerformSession(vector<Player>& Players, vector<Hero>& Heroes, int num) {
        for (int i = 0; i < num; i++) {
            Session session;
            session.TeamBlue;
            session.TeamRed;
            session.TeamCreator(Players, Heroes);
            session.GameManager(session.TeamBlue, session.TeamRed, Players, Heroes);
        };

    };
};