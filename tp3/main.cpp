#include "Maillon.hpp"
#include "Liste.hpp"
#include <iostream>
using namespace std;

int main()
{
    Liste *l = new Liste();
    (*l).ajout_queue(1);
    (*l).ajout_queue(2);
    (*l).ajout_queue(3);
    (*l).ajout_queue(4);
    (*l).ajout_queue(5);
    (*l).afficher();
    (*l).afficher_Rec((*l).getTete());
    (*l).afficher_Inverse((*l).getTete());
    cout << "Cardinal : " << (*l).cardinal() << endl;
    cout << "Chercher 3 : " << (*l).chercher(3) << endl;
    cout << "Chercher 6 : " << (*l).chercher(6) << endl;
    (*l).ajout_queue(5);
    (*l).afficher();
    cout << "Nb occurences de 5 : " << (*l).Nb_Occurences(5) << endl;
    cout << "Nb occurences de 6 : " << (*l).Nb_Occurences(6) << endl;
    (*l).afficher();
    (*l).supprimer(5);
    (*l).afficher();
    (*l).supprimer(1);
    (*l).afficher();
    (*l).supprimer(1);
    (*l).supprimer_Tout();
    (*l).afficher();
    delete l;
}