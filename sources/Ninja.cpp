#include "Ninja.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Ninja::Ninja(int speed, int hitPoints, string name, Point location)
     : Character(location,hitPoints, name), _speed(speed) {

    }

    void Ninja::move(Character* team){
        Point newLocation = getLocation().moveTowards(getLocation(), team->getLocation(), _speed); //(src, dest, speed)
        setLocation(newLocation);
    }

    void Ninja::slash(Character* team){
        if(this == team) throw runtime_error("You can't shoot yourself");
        if(!isAlive()) throw runtime_error("Ninja is dead");
        if(!team->isAlive()) throw runtime_error("Team is dead");
        if(isAlive()){ // for slash
            if (distance(team)< 1) team->hit(40);
        }
    }

    string Ninja::getCategory(){
        return "N";
    }
}