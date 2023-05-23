#ifndef NINJA_HPP
#define NINJA_HPP
#include "Ninja.hpp"
#include <string>
#include <iostream>
#include "Character.hpp"

namespace ariel {

    class Ninja : public Character
    {
    private:
        int _speed;

    public:
        Ninja(int speed, int hitPoints, string name, Point location);
        void move(Character* team);
        void slash(Character* team);
        string getCategory() override;
    };
}
#endif 
