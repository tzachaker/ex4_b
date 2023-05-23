#include "Point.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

namespace ariel 
{
    Point::Point(double x, double y)
     : _x(x) , _y(y){

    }

    double Point::distance(Point otherPoint){
        double dist = sqrt(pow(_x - otherPoint._x, 2) + pow(_y - otherPoint._y, 2));
        return dist;
    }

    string Point::print(){
        string p = "(" + to_string(_x) + " , " + to_string(_y) + ")";
        return p;
    }

    Point Point::moveTowards(Point src, Point dest, double distance) {
        if(distance< 0) throw invalid_argument("The distance should be non-negative");
        double distSrcToDest = src.distance(dest);
        if (distSrcToDest <= distance) return dest; 
        else {
            double deltaX = dest._x - src._x;
            double deltaY = dest._y - src._y;
            double proportion  = distance / distSrcToDest;
            double updatedX = src._x + (deltaX * proportion );
            double updatedY = src._y + (deltaY * proportion );
            return Point(updatedX, updatedY);
        }
    }
}