#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Character.hpp"
#include <string>
#include <iostream>
#include "Point.hpp"

namespace ariel {

    class Character
    {
        private:
            Point _location;
            int _hitPoints;
            string _name;
            bool _isPartOfTeam;
   
        public:
            Character(Point location, int hitPoints, string name);  
            bool isAlive();
            double distance(Character* otherCharacter);
            void hit(int hitNum);
            Point getLocation();
            void setLocation(Point newLocation);
            int getHitPoints();
            string getName();
            bool isPartOfTeam();
            void joinToTeam();
            virtual string getCategory();
            string print();
    };
}
#endif 
