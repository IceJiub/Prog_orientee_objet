#ifndef LISTE_RAPIDE_HPP
#define LISTE_RAPIDE_HPP
#include "Liste.hpp"

class Liste_Rapide {
    private:
        int taille;
        int nb_elements;
        Liste principale;
        Liste secondaire;
    public:
        Liste_Rapide(int taille);
        ~Liste_Rapide();
        bool chercher(int element);
        void inserer(int element);
        void supprimer(int element);
        void afficherListePrincipale();
        void afficherListeSecondaire();
};

#endif