#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "OldNinja.hpp"
#include <string>
#include <iostream>
#include "Ninja.hpp"

namespace ariel {

    class OldNinja : public Ninja
    {
        private:

        public:
            OldNinja(string name, Point location);
    };
}
#endif