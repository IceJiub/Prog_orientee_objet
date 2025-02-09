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

void Cercle::afficher()
{
    cout << "Centre : ";
    centre.afficher();
    cout << "Rayon : " << this->rayon << endl;
}

void Cercle::saisir()
{
    cout << "Centre : " << endl;
    centre.saisir();
    cout << "Rayon : " , cin >> this->rayon;
}