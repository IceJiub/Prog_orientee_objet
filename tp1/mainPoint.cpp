#include <iostream>
#include "Point.hpp"
using namespace std;

int main()
{
    Point p1(1.0, 2.0);
    p1.afficher();
    Point p2;
    p2.afficher();
    cout << p1.distance(p2) << endl;
    Point p3;
    p3.saisir();
    p3.afficher();
    int N;
    Point *tab = saisir_points(N);
    delete [] tab;
}