#include <iostream>
#include <cmath>
#include "Point.hpp"
using namespace std;

Point::Point()
{
    this->x = 0.0;
    this->y = 0.0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::afficher()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

double Point::distance(Point &p)
{
    return sqrt(((this->x)-p.x)*((this->x)-p.x) + ((this->y)-p.y)*((this->y)-p.y));
}

void afficher(Point *p, int taille)
{
    for (int i = 0 ; i < taille ; i++)
        p[i].afficher();
}

void Point::saisir()
{
    cout << "Entrer x : " , cin >> this->x;
    cout << "Entrer y : " , cin >> this->y;
}

void saisir(Point *p, int taille)
{
    for (int i = 0 ; i < taille ; i++)
    {
        cout << "Point " << i+1 << " : " << endl;
        p[i].saisir();
    }
}

Point * saisir_points(int &n)
{
    cout << "Entrer le nombre de points : " , cin >> n;
    Point *tab = new Point[n];
    saisir(tab, n);
    return tab;
}