#include "Maillon.hpp"
#include "Liste.hpp"
#include <iostream>
using namespace std;

Liste::Liste()
{
    this->tete = NULL;
}

Liste::Liste(int *tab, int nb)
{
    for (int i = 0 ; i < nb ; i++)
        this->ajout_queue(tab[i]);
}

Liste::~Liste()
{
    Maillon *courant = tete;
    Maillon *suivant = NULL;
    
    while (courant != NULL)
    {
        suivant = (*courant).suivant;
        delete courant;
        courant = suivant;
    }
}

Maillon * Liste::getTete()
{
    return tete;
}

void Liste::ajout_tete(int x)
{
    Maillon *a = new Maillon(x);
    (*a).suivant = tete;
    tete = a;
}

void Liste::ajout_queue(int x)
{
    Maillon *a = new Maillon(x);
    Maillon *pr, *c;
    pr = NULL;
    c = tete;

    while (c != NULL)
    {
        pr = c;
        c = (*c).suivant;
    }

    if (pr == NULL)
        tete = a;
    else
        (*pr).suivant = a;
}

void Liste::afficher()
{
    Maillon *courant = this->tete;
    
    while (courant != NULL)
    {
        cout << (*courant).Info << " ";
        courant = (*courant).suivant;
    }
    cout << endl;
}

void Liste::afficher_Rec(Maillon *m)
{
    if (m != NULL)
    {
        cout << (*m).Info << " ";
        afficher_Rec((*m).suivant);
    }
}