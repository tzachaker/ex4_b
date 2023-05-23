#include "Team.hpp"
#include <iostream>
#include <limits>
using namespace std;

namespace ariel
{
    Team::Team(Character* teamLeader) : _leader(teamLeader)
    {
        if(teamLeader->isPartOfTeam()) throw runtime_error("The leader is part of the team");
        teamMembers.reserve(10); //allocates memory for at least 10 element
        teamMembers.push_back(_leader);
        _leader->joinToTeam();
    }

        Team::~Team() {
        for (Character *teamMember: teamMembers) {
            delete teamMember;
        }
    }

    void Team::add(Character* newMember)
    { 
        if(newMember == nullptr) throw invalid_argument("teamMember is null");
        if(newMember->isPartOfTeam()) throw runtime_error("He cannot be in two different teams");        
        if(teamMembers.size() == 10 || teamMembers.size() > 10) throw runtime_error("No more than 10 in a team");    
        teamMembers.push_back(newMember);
        newMember->joinToTeam();
    }

    void Team::attack(Team* team)
    {
        if (this == team) throw runtime_error("team attacks itself");
        if(team == nullptr) throw invalid_argument("given null team pointer");
        if(team->stillAlive() == 0) throw runtime_error("all team is dead");
        if(!_leader->isAlive()) chooseNewLeader();
        Character* teamToAttack = chooseMemberByDist(team);
        for(Character* teamMember : sortMembersOnCategory()) {
            if(team->stillAlive()>0 && teamMember->isAlive()){
                if(!teamToAttack->isAlive()) teamToAttack = chooseMemberByDist(team);
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(teamMember)){
                    if(cowboy->hasboolets())cowboy->shoot(teamToAttack);
                    else cowboy->reload();
                } 
                if (Ninja *ninja = dynamic_cast<Ninja *>(teamMember)){
                    if(ninja->distance(teamToAttack) < 1) ninja->slash(teamToAttack);
                     else ninja->move(teamToAttack);
                }
            }
        }
    }

    int Team::stillAlive()
    {
        int aliveMembers = 0;
        for(Character* teamMember : getMembers()) {
            if(teamMember->isAlive()) aliveMembers++;
        }
        return aliveMembers;
    }

    void Team::print()
    {
        for(Character* teamMember : getMembers()) {
            teamMember->print();
        }
    }

    vector<Character*> Team::sortMembersOnCategory(){
        vector<Character*> sortedMembers = teamMembers;
        sort(sortedMembers.begin(), sortedMembers.end(), [](Character* c1, Character* c2) {
            bool c1IsCowboy = dynamic_cast<Cowboy*>(c1) != nullptr;
            bool c2IsNinja = dynamic_cast<Ninja*>(c2) != nullptr;
            if (c1IsCowboy && !c2IsNinja) return true;
            else return false; });
        return sortedMembers;
}

    vector<Character*> Team::getMembers(){
        return teamMembers;
    }

    void Team::chooseNewLeader(){
        double minDist = numeric_limits<double>::max();
        Character* newLeader;
        for (Character* member : teamMembers){
            double currDist = _leader->distance(member);
            if(member->isAlive()){
                if(currDist < minDist){
                    newLeader = member;
                    minDist = currDist;
                }
            }
        }
        _leader = newLeader;
    }

    Character* Team::chooseMemberByDist(Team* team)
    {
        double minDist = numeric_limits<double>::max();
        Character* teamToAttack;
        for(Character* member : team->sortMembersOnCategory()) {
            double currDist = this->_leader->distance(member);
            if(member->isAlive()){
                if(currDist < minDist){
                    teamToAttack = member;
                    minDist = currDist;
                }
            }
        }
        return teamToAttack;
    }
}