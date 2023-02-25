/*
 *Name/Surname: Kerem Tekik
 *Section: 2
 * Student Number: 22002730
 */
#ifndef LEAGUEMANAGEMENTSYSTEM_TEAM_H
#define LEAGUEMANAGEMENTSYSTEM_TEAM_H

#include <string>
#include "Player.h"

using namespace std;

class Team{
public:
    string teamName;
    int foundationYear;
    Player** teamRoster;
    Team(string teamName, int foundationYear);
    Team(const Team* other);
    ~Team();
    int rosterSize;
};


#endif //LEAGUEMANAGEMENTSYSTEM_TEAM_H
