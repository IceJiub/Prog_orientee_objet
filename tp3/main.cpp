#include "Maillon.hpp"
#include "Liste.hpp"
#include <iostream>
using namespace std;

int main()
{
    int tab[10] = {1,2,3,4,5,6,7,8,9,0};
    Liste L(tab,10);

    // Tests des fonctions d'affichages
    L.afficher();
    L.afficher_Rec(L.getTete());
    L.afficher_Inverse(L.getTete());

    // Test cardinal()
    cout << "Nombre d'éléments de la liste : " << L.cardinal() << endl;

    // Test chercher()
    cout << "Recherche 1 : " << L.chercher(1) << endl;
    cout << "Recherche 99 : " << L.chercher(99) << endl;

    // Test nb_Occurence()
    cout << "Recherche occurence 5 : " << L.nb_Occurence(5) << endl;
    L.ajout_queue(5);
    L.afficher();
    cout << "Recherche occurence 5 : " << L.nb_Occurence(5) << endl;

    // Test supprimer()
    cout << "Suppression 5" << endl;
    L.supprimer(5);
    L.afficher();
    cout << "Suppression 99" << endl;
    L.supprimer(99);
    cout << "Suppression 1" << endl;
    L.supprimer(1);
    L.afficher();

    // Test supprimer_tout()
    L.ajout_queue(4);
    L.ajout_queue(4);
    L.ajout_queue(4);
    L.afficher();
    L.supprimer_Tout(4);
    L.afficher();
    
    // Test du constructeur par copie
    Liste L1(L);
    L1.afficher();
}