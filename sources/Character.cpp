#include "Character.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Character::Character(Point location, int hitPoints, string name)
    :_location(location), _hitPoints(hitPoints), _name(name), _isPartOfTeam(false){
        
    }

    bool Character::isAlive() {
        if (_hitPoints > 0)
            return true;
        return false;
    }

    double Character::distance(Character* otherCharacter) {
        double dist = _location.distance(otherCharacter->getLocation());
        return dist;
    }

    void Character::hit(int hitNum) {
        if(hitNum < 0 ) throw invalid_argument("hitNum must to be positive num");
        _hitPoints -= hitNum;
    }

    Point Character::getLocation(){
        return _location;
    }

    void Character::setLocation(Point newLocation){
        _location = newLocation;
    }

    int Character::getHitPoints(){
        return _hitPoints;
    }

    string Character::getName(){
        return _name;
    }

    bool Character::isPartOfTeam(){
        return _isPartOfTeam;
    }

    void Character::joinToTeam(){
        _isPartOfTeam = true;
    }

    string Character::print(){
        string forLiving, forDead;
        if(isAlive()){
            forLiving = "fighter : "+ getCategory() + " " + getName()+" , hitPoints : "+to_string(_hitPoints)+" , location : "+getLocation().print();
            return forLiving;
        }
        forDead = "fighter : " +getCategory() + " " + getName()+" , hitPoints : 0 ,  location : " + getLocation().print() + " ---------> R.I.P";
        return forDead;
    }

    string Character::getCategory(){
    //used later
        return "";
    }
}