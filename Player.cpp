/*
 *Name/Surname: Kerem Tekik
 *Section: 2
 * Student Number: 22002730
 */
#include "Player.h"
#include  <string>
#include <iostream>



Player::Player(string fName, int jNumber, int sAmount) {
    fullName = fName;
    jerseyNumber = jNumber;
    salaryAmount = sAmount;
}


Player::Player(const Player* other) {

    this->salaryAmount = other->salaryAmount;
    this->jerseyNumber = other->jerseyNumber;
    this->fullName = other->fullName;
}

Player::~Player() {

    }