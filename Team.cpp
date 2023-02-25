/*
 *Name/Surname: Kerem Tekik
 *Section: 2
 * Student Number: 22002730
 */
#include "Team.h"
#include "Player.h"
using namespace std;
#include <iostream>


Team::Team(string tName, int fYear) {
    teamName = tName;
    foundationYear = fYear;
    rosterSize =0;
    teamRoster = NULL;
}

Team::~Team() {
    for( int i = 0; i < rosterSize && teamRoster != NULL; i++) {
        delete teamRoster[i];
        teamRoster[i] = NULL;
    }
    if(teamRoster != NULL && rosterSize != 1){
        delete [] teamRoster;
        teamRoster = NULL;
    }
    else if(teamRoster != NULL && rosterSize == 1){
        delete teamRoster;
        teamRoster = NULL;
    }
}

Team::Team(const Team* rhs) {
    this->teamName = rhs->teamName;
    this->foundationYear = rhs->foundationYear;
    this->rosterSize = rhs->rosterSize;
    this->teamRoster = NULL;
    if(rhs->rosterSize != 0) {
        this->teamRoster = new Player*[rhs->rosterSize];
        for(int i = 0; i < rhs->rosterSize; i++) {
            this->teamRoster[i] = new Player(rhs->teamRoster[i]);
        }
    }
};
