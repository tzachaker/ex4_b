#ifndef TEAM2_HPP
#define TEAM2_HPP
#include <string>
#include <iostream>
#include "Team.hpp"

namespace ariel {

    class Team2 : public Team
    {
        private:

        public:
            Team2(Character* leader);
            vector<Character*> sortMembersOnCategory() override;
    };
}
#endif
