/*
 *Name/Surname: Kerem Tekik
 *Section: 2
 * Student Number: 22002730
 */
#include <string>
#include "Player.h"
#include "Team.h"
using namespace std;
#ifndef LEAGUEMANAGEMENTSYSTEM_LEAGUEMANAGEMENTSYSTEM_H
#define LEAGUEMANAGEMENTSYSTEM_LEAGUEMANAGEMENTSYSTEM_H


class LeagueManagementSystem {

public:
    Team** teams = NULL;
    LeagueManagementSystem();
    ~LeagueManagementSystem();
    void addTeam( const string name, const int year );
    void removeTeam( const string name );
    void addPlayer( const string teamName, const string playerName,
                    const int jersey, const int salary );
    void removePlayer( const string teamName, const string playerName );
    void transferPlayer( const string playerName,
                         const string departTeamName, const string arriveTeamName );
    void showAllTeams() const;
    void showTeam( const string name ) const;
    void showPlayer( const string name ) const;

    int arrSize;
};


#endif //LEAGUEMANAGEMENTSYSTEM_LEAGUEMANAGEMENTSYSTEM_H
