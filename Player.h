/*
 *Name/Surname: Kerem Tekik
 *Section: 2
 * Student Number: 22002730
 */
#ifndef LEAGUEMANAGEMENTSYSTEM_PLAYER_H
#define LEAGUEMANAGEMENTSYSTEM_PLAYER_H

#include <string>

using namespace std;

class Player{

    string fullName;
    int jerseyNumber;
    int salaryAmount;
public:

    string getFullName() {return fullName;}
    int getJerseyNumber() {return jerseyNumber;}
    int getSalaryAmount() {return salaryAmount;}

    Player(const Player* other);
    Player(string fullName, int jerseyNumber, int salaryAmount);
    ~Player();
};

#endif //LEAGUEMANAGEMENTSYSTEM_PLAYER_H
