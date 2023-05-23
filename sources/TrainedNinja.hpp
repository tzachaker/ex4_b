#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "TrainedNinja.hpp"
#include <string>
#include <iostream>
#include "Ninja.hpp"

namespace ariel {

    class TrainedNinja : public Ninja
    {
        private:

        public:
            TrainedNinja(string name, Point location);
    };
}
#endif