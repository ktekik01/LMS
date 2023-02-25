/*
 *Name/Surname: Kerem Tekik
 *Section: 2
 * Student Number: 22002730
 */

#include "LeagueManagementSystem.h"
#include "Team.h"
#include<iostream>
using namespace std;

LeagueManagementSystem::LeagueManagementSystem() {
    arrSize= 0;
}


LeagueManagementSystem::~LeagueManagementSystem() {
	for( int i = 0; i < arrSize; i++) {
		delete teams[i];
        teams[i] = NULL;
	}
    delete [] teams;
    teams = NULL;
}



void LeagueManagementSystem::addTeam(const string name, const int year) {

    for(int i = 0; i< arrSize; i++){
        if(name == teams[i]->teamName){
            cout<<"Cannot add team. Team "<<name<<" already exists."<<endl;
            return;
        }
    }

    Team** temp = NULL;
    if(teams != NULL){
        temp = new Team*[arrSize];

        for(int i= 0; i<arrSize; i++){
            temp[i] = new Team(teams[i]);// = teams[0];
        }
        for(int i = 0; i<arrSize; i++){
            delete teams[i];
            teams[i] = NULL;

        }
        delete [] teams;
        teams = NULL;
    }

    teams = new Team*[arrSize+1];
    if(temp != NULL) {
        for(int i=0; i< arrSize; i++){
            teams[i] = new Team(temp[i]);
        }
        for(int i = 0; i<arrSize; i++){
            delete temp[i];
            temp[i] = NULL;
        }
        delete [] temp;
        temp = NULL;
    }


    teams[arrSize] = new Team(name, year);

    arrSize = arrSize+ 1;
    cout<<"Added team "<<name<<"."<<endl;
}



void LeagueManagementSystem::removeTeam(const string name) {

    if(arrSize == 0){
        cout <<"Cannot remove team. Team "<<name<<" does not exist."<<endl;
        return;
    }

    Team** temp =NULL;
    temp = new Team*[arrSize-1];
    for( int i = 0;  i < arrSize - 1; i++) {
        temp[i] = NULL;
    }
    bool check = false;
    int foundAt = 0;

    for(int team_index=0; team_index<arrSize; team_index++) {
        if (name == teams[team_index]->teamName) {
            check = true;
            foundAt = team_index;
            break;
        }
    }
    if(check == false) {
        cout <<"Cannot remove team. Team "<<name<<" does not exist."<<endl;
        delete [] temp;
        temp = NULL;
        return;
    }
    else{
        int temp_index=0;

        for (int player_index = 0; player_index < teams[foundAt]->rosterSize; player_index++) {
            delete teams[foundAt]->teamRoster[player_index];
            teams[foundAt]->teamRoster[player_index] = NULL;
        }
        delete [] teams[foundAt]->teamRoster;
        teams[foundAt]->teamRoster = NULL;
        delete teams[foundAt];
        teams[foundAt] = NULL;


        for(int team_index=0; team_index<arrSize; team_index++) {

            if(teams[team_index] != NULL) {
                temp[temp_index] = new Team(teams[team_index]);
                temp_index++;
                delete teams[team_index];
                teams[team_index] = NULL;
            }
        }
        delete [] teams;
        teams = NULL;
    }

    arrSize--;
    teams = new Team*[arrSize];
    for(int team_index=0; team_index<arrSize; team_index++) {
        if(temp[team_index]!=NULL)
            teams[team_index] = new Team(temp[team_index]);
    }
    for(int temp_index=0; temp_index<arrSize; temp_index++){
        delete temp[temp_index];
        temp[temp_index] = NULL;
    }
    delete [] temp;
    temp = NULL;

    cout<<"Removed team "<<name<<"."<<endl;
}

void LeagueManagementSystem::addPlayer(const string teamName, const string playerName, const int jersey,
                                       const int salary) {
    for(int team_index =0; team_index<arrSize; team_index++){
        if(teamName==teams[team_index]->teamName){
            for(int i = 0; i<teams[team_index]->rosterSize; i++) {
                if (jersey == teams[team_index]->teamRoster[i]->getJerseyNumber()) {
                    cout<<"Cannot add player. Jersey number "<<jersey<<" already exists in team "<<teamName<<"."<<endl;
                    return;
                }
            }
            Player** temp = NULL;

            if(teams[team_index]->teamRoster != NULL){
                temp = new Player*[teams[team_index]->rosterSize + 1];
                for( int q = 0; q < teams[team_index]->rosterSize + 1; q++) {
                    temp[q] = NULL;
                }

                for(int u= 0; u<teams[team_index]->rosterSize; u++){
                    temp[u] = new Player(teams[team_index]->teamRoster[u]);
                }
                for(int u = 0; u<teams[team_index]->rosterSize; u++){
                    delete teams[team_index]->teamRoster[u];
                    teams[team_index]->teamRoster[u] = NULL;
                }
                delete  [](teams[team_index]->teamRoster);
                teams[team_index]->teamRoster = NULL;
            }

            teams[team_index]->teamRoster = new Player*[teams[team_index]->rosterSize+1];
            for(int u = 0; u< teams[team_index]->rosterSize; u++){
                teams[team_index]->teamRoster[u] = NULL;
            }
            if(temp != NULL){
                for(int u = 0; u< teams[team_index]->rosterSize; u++){
                    teams[team_index]->teamRoster[u] = new Player(temp[u]);
                }
                for(int u= 0; u<teams[team_index]->rosterSize; u++){
                    delete temp[u];
                    temp[u] = NULL;
                }
                delete [] temp;
                temp = NULL;
            }
            teams[team_index]->teamRoster[teams[team_index]->rosterSize] = new Player(playerName,jersey,salary);

            teams[team_index]->rosterSize = teams[team_index]->rosterSize + 1;
            cout<<"Added player "<<playerName<<" to team "<<teamName<<"."<<endl;
            return;

        }
    }

    cout<<"Cannot add player. Team "<<teamName<<" does not exist."<<endl;
    return;

}


void LeagueManagementSystem::removePlayer(const string teamName, const string playerName) {
    bool playerCheck = false;
    bool teamCheck = false;
    for(int team_index=0; team_index<arrSize; team_index++){
        if(teams[team_index]->teamName==teamName){
            teamCheck = true;
            for(int player_index=0; player_index<teams[team_index]->rosterSize; player_index++){
                if(teams[team_index]->teamRoster[player_index]->getFullName()==playerName){
                    playerCheck = true;
                    Player** temp = NULL;
                    if(teams[team_index]->teamRoster != NULL) {
                        if((teams[team_index]->rosterSize-1) < 1){
                            player_index = 0;
                            delete teams[team_index]->teamRoster[player_index];
                            teams[team_index]->teamRoster[player_index] = NULL;
                            cout<<"Removed player "<<playerName<<" from team "<<teamName<<"."<<endl;
                            teams[team_index]->rosterSize = teams[team_index]->rosterSize -1;
                        }
                        else{
                            temp = new Player*[(teams[team_index]->rosterSize)-1];
                            int temp_index = 0;
                            for(player_index=0; player_index<teams[team_index]->rosterSize; player_index++){
                                if(teams[team_index]->teamRoster[player_index]->getFullName()==playerName){
                                    delete teams[team_index]->teamRoster[player_index];
                                    cout<<"Removed player "<<playerName<<" from team "<<teamName<<"."<<endl;
                                    teams[team_index]->teamRoster[player_index] = NULL;
                                }
                                else{
                                    temp[temp_index] = new Player(teams[team_index]->teamRoster[player_index]);
                                    temp_index++;
                                }
                            }
                            for(int u = 0; u < teams[team_index]->rosterSize; u++){
                                if(teams[team_index]->teamRoster[u]==NULL) continue;
                                delete teams[team_index]->teamRoster[u];
                                teams[team_index]->teamRoster[u] = NULL;
                            }
                            teams[team_index]->rosterSize = teams[team_index]->rosterSize -1;
                            delete [] teams[team_index]->teamRoster;
                            teams[team_index]->teamRoster = NULL;
                            teams[team_index]->teamRoster = new Player*[teams[team_index]->rosterSize];
                            for(int a =0; a<teams[team_index]->rosterSize; a++){
                                teams[team_index]->teamRoster[a] = new Player(temp[a]);
                            }
                            for(int index=0; index<temp_index; index++){
                                delete temp[index];
                                temp[index] = NULL;
                            }
                            delete [] temp;
                            temp = NULL;

                            return;
                        }

                    }
                }
            }
        }
    }
    if(!teamCheck){
        cout<<"Cannot remove player. Team "<<teamName<<" does not exist. "<<endl;
        return;
    }

    if(!playerCheck){
        cout<<"Cannot remove player. Player "<<playerName<<" does not exist."<<endl;
        return;
    }
}



void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName,
                                            const string arriveTeamName) {
    bool departureCheck = false;
    bool arriveCheck = false;
    bool nameCheck = false;
    int departureIndex;
    int arriveIndex;
    for(int team_index=0; team_index<arrSize; team_index++){
        if(teams[team_index]->teamName==departTeamName){
            departureCheck = true;
            departureIndex = team_index;
        }
        if(teams[team_index]->teamName==arriveTeamName){
            arriveCheck = true;
            arriveIndex = team_index;
        }
    }
    if(!departureCheck){
        cout<<"Cannot transfer player. "<<"Team "<<departTeamName<<" does not exist."<<endl;
        return;
    }
    else if(!arriveCheck){
        cout<<"Cannot transfer player. "<<"Team "<<arriveTeamName<<" does not exist."<<endl;
        return;
    }
    int y = 0;
        for(y = 0; y<teams[departureIndex]->rosterSize; y++){
            if(playerName==teams[departureIndex]->teamRoster[y]->getFullName()){
                nameCheck = true;
                break;
            }
            else{
                nameCheck = false;

            }
        }
    if(!nameCheck){
        cout<<"Cannot transfer player. Player "<<playerName<<" does not exist."<<endl;
        return;
    }
    for(int a = 0; a<teams[arriveIndex]->rosterSize; a++){
        if(teams[arriveIndex]->teamRoster[a]->getJerseyNumber() == teams[departureIndex]->teamRoster[y]->getJerseyNumber()){
            cout<<"Cannot transfer player. Jersey number "<<teams[departureIndex]->teamRoster[y]->getJerseyNumber()
                <<" already exists in team "<<teams[arriveIndex]->teamName<<"."<<endl;
            return;
        }
    }

    Player** temp = NULL;
    Player* tempPlayer = NULL;
    int player_index;
    int temp_index = 0;
    temp = new Player*[teams[departureIndex]->rosterSize-1];
    for(player_index=0; player_index<teams[departureIndex]->rosterSize; player_index++){
        if(playerName==teams[departureIndex]->teamRoster[player_index]->getFullName()){
            tempPlayer = new Player(teams[departureIndex]->teamRoster[player_index]);
        }
        else{
            temp[temp_index] = new Player(teams[departureIndex]->teamRoster[player_index]);
            temp_index++;
        }
        delete teams[departureIndex]->teamRoster[player_index];
        teams[departureIndex]->teamRoster[player_index] = NULL;
    }
    delete [] teams[departureIndex]->teamRoster;
    teams[departureIndex]->teamRoster = NULL;
    teams[departureIndex]->rosterSize -= 1;
    if(teams[departureIndex]->rosterSize == 0){
        teams[departureIndex]->teamRoster = NULL;
    }
    else{
        teams[departureIndex]->teamRoster = new Player*[teams[departureIndex]->rosterSize];
    }
    for(int temp_player_index=0; temp_player_index<teams[departureIndex]->rosterSize; temp_player_index++){
        teams[departureIndex]->teamRoster[temp_player_index] = new Player(temp[temp_player_index]);
    }
    for(int temp_index=0; temp_index<teams[departureIndex]->rosterSize; temp_index++){
        delete temp[temp_index];
        temp[temp_index] = NULL;
    }
    delete [] temp;
    temp = NULL;

    temp = new Player*[teams[arriveIndex]->rosterSize+1];
    for( int i = 0; i < teams[arriveIndex]->rosterSize; i++) {
        temp[i] = NULL;
    }
    int temp_player_index  = 0;
    for(; temp_player_index<teams[arriveIndex]->rosterSize; temp_player_index++){
        temp[temp_player_index] = new Player(teams[arriveIndex]->teamRoster[temp_player_index]);
    }
    int tempPlayer_index = temp_player_index;
    temp[tempPlayer_index] = new Player(tempPlayer);
    delete tempPlayer; tempPlayer = NULL;

    for(int index=0; index < teams[arriveIndex]->rosterSize; index++){
        delete teams[arriveIndex]->teamRoster[index];
        teams[arriveIndex]->teamRoster[index] = NULL;
    }
    delete [] teams[arriveIndex]->teamRoster;
    teams[arriveIndex]->teamRoster = NULL;

    teams[arriveIndex]->rosterSize += 1;
    teams[arriveIndex]->teamRoster = new Player*[teams[arriveIndex]->rosterSize];
    for(int i = 0; i < temp_player_index+1; i++){
        teams[arriveIndex]->teamRoster[i] = new Player(temp[i]);
        delete temp[i];
        temp[i] = NULL;
    }
    delete []temp;
    temp = NULL;

    cout<<"Transferred player "<<playerName<<" from team "<<departTeamName<<" to team "<<arriveTeamName<<"."<<endl;

}



void LeagueManagementSystem::showAllTeams() const {
    cout<<"Teams in the league management system: "<<endl;
    if(arrSize == 0){
        cout<<"None"<<endl;
    }
    for(int i = 0; i < arrSize; i++){
        int totalSalary = 0;
        for(int u=0; u<teams[i]->rosterSize; u++){
            totalSalary = totalSalary + teams[i]->teamRoster[u]->getSalaryAmount();
        }
        cout<<teams[i]->teamName;
        cout<<", "<<teams[i]->foundationYear;
        cout<<", "<<teams[i]->rosterSize<<" players, ";
        cout<<totalSalary<<" TL total salary";
        cout<<endl;
    }
}
void LeagueManagementSystem::showTeam(const string name) const {
    bool check = false;
    int teamIndex;
    int totalSalary = 0;
    for(int team_index=0; team_index<arrSize; team_index++){
	    if(teams[team_index]->teamName == name){
            check = true;
            teamIndex = team_index;
        }
    }
    if(!check){
        cout<<"Team "<<name<<" does not exist."<<endl;
	return;
    }
    for(int a = 0; a< teams[teamIndex]->rosterSize; a++ ){
        totalSalary = totalSalary + teams[teamIndex]->teamRoster[a]->getSalaryAmount();
    }
        cout<<"Team: "<<endl;
        cout<<teams[teamIndex]->teamName;
        cout<<", "<<teams[teamIndex]->foundationYear;
        cout<<", "<<teams[teamIndex]->rosterSize<<" players, ";
        cout<<totalSalary<<" TL total salary";
        cout<<endl<<"Players:"<<endl;

        for(int u=0; u<teams[teamIndex]->rosterSize; u++){
            cout<<teams[teamIndex]->teamRoster[u]->getFullName();
            cout<<", jersey "<<teams[teamIndex]->teamRoster[u]->getJerseyNumber();
            cout<<", "<<teams[teamIndex]->teamRoster[u]->getSalaryAmount()<<" TL salary "<<endl;
        }

}
void LeagueManagementSystem::showPlayer(const string name) const {
    bool check = false;
    int team_index;
    int player_index;
    for(team_index = 0; team_index<arrSize; team_index++){
        for(player_index = 0; player_index<teams[team_index]->rosterSize; player_index++){
            if(name== teams[team_index]->teamRoster[player_index]->getFullName()){
                check = true;
                break;
            }
        }if(check) break;
    }
    if(!check){
        cout<<"Player "<<name<<" does not exist."<<endl;
    }
    else{
        cout<<"Player: "<<endl;
        cout<<teams[team_index]->teamRoster[player_index]->getFullName()<<", jersey "<<
            teams[team_index]->teamRoster[player_index]->getJerseyNumber()<<", "<<teams[team_index]->teamRoster[player_index]->getSalaryAmount()
            <<" TL salary"<<endl<<"Plays in team "<<teams[team_index]->teamName<<"."<<endl;
    }
}
