#include <iostream>
#include "Point.hpp"
#include "Cercle.hpp"
using namespace std;

int main()
{
    Point p1(1.0, 2.0);
    p1.afficher();
    Cercle c1(p1, 3.0);
    c1.afficher();
    Cercle c2;
    c2.saisir();
    c2.afficher();
}