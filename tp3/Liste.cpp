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
    this->tete = NULL;
    for (int i = 0 ; i < nb ; i++)
        this->ajout_queue(tab[i]);
}

Liste::Liste(const Liste &L)
{
    this->tete = L.tete;
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
    Maillon *courant = this->tete;
    Maillon *pr = NULL;

    while (courant != NULL)
    {
        pr = courant;
        courant = (*courant).suivant;
    }

    if (pr == NULL)
        tete = a;
    else
        (*pr).suivant = a;
}

void Liste::afficher()
{
    if (this->tete == NULL)
    {
        cout << "Liste vide" << endl;
        return;
    }
    
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

void Liste::afficher_Inverse(Maillon *m)
{
    if (m != NULL)
    {
        afficher_Inverse((*m).suivant);
        cout << (*m).Info << " ";
    }
    else
        cout << endl;
}

int Liste::cardinal()
{
    Maillon *courant = this->tete;
    int cpt = 0;
    
    while (courant != NULL)
    {
        cpt++;
        courant = (*courant).suivant;
    }
    
    return cpt;
}

bool Liste::chercher(int x)
{
    Maillon *courant = this->tete;

    while (courant != NULL)
    {
        if ((*courant).Info == x)
            return true;
        courant = (*courant).suivant;
    }
    
    return false;
}

int Liste::nb_Occurence(int x)
{
    Maillon *courant = this->tete;
    int cpt = 0;

    while (courant != NULL)
    {
        if ((*courant).Info == x)
            cpt++;
        courant = (*courant).suivant;
    }

    return cpt;
}

void Liste::supprimer(int x)
{
    Maillon *courant = this->tete;
    Maillon *pr = NULL;

    // Tant qu'on n'a pas atteint le dernier maillon ET qu'on n'a pas trouvé l'élément x
    while (courant != NULL && (*courant).Info != x)
    {
        pr = courant;
        courant = (*courant).suivant;
    }
    // Si on a atteint le dernier maillon sans trouvé l'élément
    if (courant == NULL)
        cout << "Element " << x << " non trouvé" << endl;
    // Si on a trouvé l'élément x dans la liste
    else
    {
        if (pr == NULL)
            tete = (*courant).suivant;
        else
            (*pr).suivant = (*courant).suivant;
        delete courant;
    }
}

void Liste::supprimer_Tout(int x)
{
    Maillon *courant = this->tete;
    Maillon *pr = NULL;

    // On parcourt la liste jusqu'à la fin
    while (courant != NULL)
    {
        // Si on trouve x dans la liste
        if ((*courant).Info == x)
        {
            // On decalle les cases
            (*pr).suivant = (*courant).suivant;
            // On supprime la case actuelle
            delete courant;
        }
        // Si on ne trouve pas x dans la case actuelle, on passse à la suivante
        else
            pr = courant;
            courant = (*courant).suivant;
    }
}