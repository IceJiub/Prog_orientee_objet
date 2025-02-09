#include <iostream>
#include "Point.hpp"
#include "CollectionPoints.hpp"
using namespace std;

int main()
{
    Col_Points col1(5);
    col1.ajouter(Point(1, 2));
    col1.ajouter(Point(2, 3));
    col1.ajouter(Point(1, 2));
    col1.ajouter(Point(5, 6));
    col1.supprimer(Point(5, 6));
    cout << "Collection 1 : " << endl;
    col1.afficher();

    cout << "Capacité actuelle de la collection : " << col1.getCap() << endl;
    col1.ajouter(Point(3, 4));
    col1.ajouter(Point(5, 6));
    col1.ajouter(Point(6, 7));
    col1.ajouter_bis(Point(7, 8));
    cout << "Collection 1 : " << endl;
    col1.afficher();
    cout << "Capacité actuelle de la collection : " << col1.getCap() << endl;

    Col_Points col2;
    int N;
    Point *tab = saisir_points(N);
    col2.ajouterTab(tab, N);
    cout << "Collection 2 : " << endl;
    col2.afficher();
    delete [] tab;

    Col_Points col3(col1, col2);
    cout << "Collection 3 : " << endl;
    col3.afficher();

    Col_Points col4;
    col1.intersection(col3, col4);
    cout << "Collection 4 : " << endl;
    col4.afficher();
    
    cout << "Résultat collection 4 : " << endl;
    col4.afficherResultat();
    cout << "Résultat collection 2 : " << endl;
    col2.afficherResultat();
}