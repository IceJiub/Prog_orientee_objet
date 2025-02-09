#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "Point.hpp"

class Cercle
{
    private:
        Point centre;
        double rayon;
    public:
        Cercle();
        Cercle(Point centre, double rayon);
};