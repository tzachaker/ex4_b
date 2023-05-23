#include "SmartTeam.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{

    SmartTeam::SmartTeam(Character* leader) : Team(leader){

    }

    Character* SmartTeam::chooseMemberByWeakness(Team* team){
        double minHitPoints = numeric_limits<double>::max();
        Character* memberToAttack;
        for(Character* teamMember : team->getMembers()) {
            double currMinHitPoints = teamMember->getHitPoints();
            if(teamMember->isAlive()){
                if(currMinHitPoints < minHitPoints){
                    memberToAttack = teamMember;
                    minHitPoints = currMinHitPoints;
                }
            }
        }
        return memberToAttack;
    }

}
