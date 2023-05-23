#ifndef POINT_HPP
#define POINT_HPP
#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel {

    class Point
    {
        private:
            double _x;
            double _y;

        public:
            Point(double x, double y);
            double distance(Point otherPoint);
            string print();
            static Point moveTowards(Point src, Point dest, double distance);
    };
}
#endif

