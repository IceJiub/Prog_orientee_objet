#include <iostream>
#include "Liste.hpp"
#include "Liste_Rapide.hpp"

using namespace std;

int main()
{
    int taillePrincipale = 10; // Taille de la liste principale, modifiable
    Liste_Rapide liste(taillePrincipale);

    char operation;
    int valeur;

    while (cin >> operation >> valeur)
    {
        if (operation == 's')
        {
            bool found = liste.chercher(valeur);
            if (found)
                cout << "Recherche : " << valeur << " -> Trouvé" << endl;
            else
                cout << "Recherche : " << valeur << " -> Absent" << endl;
        }
        else if (operation == 'i')
        {
            liste.inserer(valeur);
        }
        else if (operation == 'r')
            liste.supprimer(valeur);
        else
            cout << "Opération inconnue" << endl;
    }

    liste.afficherListePrincipale();
    liste.afficherListeSecondaire();

    return 0;
}