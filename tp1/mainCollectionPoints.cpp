#include <iostream>
#include "Point.hpp"
#include "CollectionPoints.hpp"
using namespace std;

int main()
{
    Col_Points col1(10);
    cout << col1.ajouter(Point(1, 2)) << endl;
    cout << col1.ajouter(Point(3, 4)) << endl;
    cout << col1.ajouter(Point(1, 2)) << endl;
    cout << col1.ajouter(Point(5, 6)) << endl;
    cout << col1.supprimer(Point(5, 6)) << endl;
    Col_Points col2(3);
    cout << col2.ajouter(Point(1, 2)) << endl;
    cout << col2.ajouter(Point(3, 4)) << endl;
    cout << col2.ajouter(Point(5, 6)) << endl;
    cout << col2.ajouter_bis(Point(7, 8)) << endl;
    cout << col2.getCap() << endl;
}