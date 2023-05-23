#ifndef TEAM_HPP
#define TEAM_HPP
#include "Team.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

namespace ariel {

    class Team
    {
        private:
            Character* _leader;
            vector<Character*> teamMembers;

        public:
            Team(Character* leader);
            void add(Character* newMember);
            void attack(Team* team);
            int stillAlive();
            void print();
            vector<Character*> getMembers();
            virtual vector<Character*> sortMembersOnCategory();
            void chooseNewLeader();
            Character* chooseMemberByDist(Team* team);// choose closest team to attack
            ~Team();
    };  
}
#endif 
