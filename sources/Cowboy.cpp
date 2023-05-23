#include "Cowboy.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
        Cowboy::Cowboy(string name, Point location)
         : Character(location,110, name), _numBalls(6) {

        }

    void Cowboy::shoot(Character* team) {
        if(this == team) throw runtime_error("You can't shoot yourself");
        if(!isAlive()) throw runtime_error("Cowboy is dead");
        if(!team->isAlive()) throw runtime_error("Team is dead");
        if(isAlive()){
            if(hasboolets()){
                team->hit(10); _numBalls--;
            }
        }      
    }

    bool Cowboy::hasboolets(){
        if (_numBalls > 0) return true;
        return false;
    }

    void Cowboy::reload(){
        if (isAlive()) _numBalls = 6;
        else throw runtime_error("Cowboy is dead");
    }

    string Cowboy::getCategory() {
        return "C";
    }
}