#include "Liste_Rapide.hpp"
#include "Liste.hpp"
#include <iostream>
using namespace std;

Liste_Rapide::Liste_Rapide(int taille)
{
    this->taille = taille;
    this->nb_elements = 0;
    this->principale = Liste();
    this->secondaire = Liste();
}

Liste_Rapide::~Liste_Rapide()
{
    // delete this->principale;
    // delete this->secondaire;
}

bool Liste_Rapide::chercher(int element)
{
    // Si l'élément est dans la liste principale
    if (this->principale.chercher(element))
    {
        return true;
    }
    // Si l'élément est dans la liste secondaire
    if (this->secondaire.chercher(element))
    {
        // On récupère le dernier maillon de liste principale
        Maillon * dernier = this->principale.getDernierMaillon();
        // On ajoute à la tete de la liste secondaire l'élément du dernier maillon de la liste principale
        this->secondaire.ajout_tete(dernier->getInfo());
        // On supprime le dernier élément de la liste principale
        this->principale.supprimer(dernier->getInfo());
        // On supprime l'élément de la liste secondaire
        this->secondaire.supprimer(element);
        // On ajoute l'élément à la queue de la liste principale
        this->principale.ajout_queue(element);
        return true;
    }
    return false;
}

void Liste_Rapide::inserer(int element)
{
    // Si l'élément est déjà dans la liste, rien à faire
    if (chercher(element))
        return; 

    // On ajoute l'élément à la tête de la liste principale
    this->principale.ajout_tete(element);
    nb_elements++;

    // Si la liste principale est pleine, on déplace le dernier élément de la liste principale à la tête de la liste secondaire
    if (nb_elements > taille)
    {
        // On récupère le dernier maillon de liste principale
        Maillon * dernier = this->principale.getDernierMaillon();

        if (dernier != NULL)
        {
            // On ajoute à la tete de la liste secondaire l'élément du dernier maillon de la liste principale
            this->secondaire.ajout_tete(dernier->getInfo());
            // On supprime le dernier élément de la liste principale
            this->principale.supprimer(dernier->getInfo());
            nb_elements--;
        }        
    }
}

void Liste_Rapide::supprimer(int element)
{
    // Si on trouve l'élément dans la liste principale
    if (this->principale.chercher(element))
    {
        // On le supprime
        this->principale.supprimer(element);

        // Si la liste secondaire n'est pas vide
        if (this->secondaire.getTete() != NULL) {
            // On ajoute à la queue de la liste principale l'élément en tête de la liste secondaire
            this->principale.ajout_queue(this->secondaire.getTete()->getInfo());
            // Puis on supprime cet élément de la liste secondaire
            this->secondaire.supprimer(this->secondaire.getTete()->getInfo());
        }
    }
    // Si on trouve l'élément dans la liste secondaire, on le supprime
    else if (this->secondaire.chercher(element))
        this->secondaire.supprimer(element);
    // Si on ne trouve pas l'élement
    else
        cout << "Suppression " << element << " -> Absent" << endl;
}

void Liste_Rapide::afficherListePrincipale()
{
    cout << "Liste Principale : ";
    this->principale.afficher();
}

void Liste_Rapide::afficherListeSecondaire()
{
    cout << "Liste Secondaire : ";
    this->secondaire.afficher();
}