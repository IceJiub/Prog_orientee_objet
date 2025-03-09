#ifndef LISTE_HPP
#define LISTE_HPP

#include "Maillon.hpp"

class Liste
{
    Maillon * tete;
    public :
        Liste();
        Liste(int *tab, int nb);
        Liste(const Liste &L);
        ~Liste();
        Maillon * getTete();
        Maillon * getDernierMaillon();
        friend class Liste_Rapide;
        void ajout_tete(int x);
        void ajout_queue(int x);
        void afficher();
        void afficher_Rec(Maillon *m);
        void afficher_Inverse(Maillon *m);
        int cardinal();
        bool chercher(int x);
        int nb_Occurence(int x);
        void supprimer(int x);
        void supprimer_Tout(int x);
};

#endif