#include <iostream>
#include "Point.hpp"
#include "Cercle.hpp"
using namespace std;

Cercle::Cercle()
{
    centre = Point();
    rayon = 0;
}

Cercle::Cercle(Point centre, double rayon)
{
    this->centre = centre;
    this->rayon = rayon;
}