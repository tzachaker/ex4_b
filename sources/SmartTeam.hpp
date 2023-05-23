#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP
#include <string>
#include <iostream>
#include "Team.hpp"

namespace ariel {

    class SmartTeam : public Team
    {
        private: 

        public:
            SmartTeam(Character* leader);
            Character* chooseMemberByWeakness(Team* team);// choose weakest member to attack
    };
}
#endif 

