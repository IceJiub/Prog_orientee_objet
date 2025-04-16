#ifndef ARBRE_HPP
#define ARBRE_HPP
#include "Arbre.hpp"

class Noeud
{
    char type;
    char op;
    double val;
    Noeud * fg, * fd;
    friend class Arbre;
    public:
        Noeud();
        Noeud(double hauteur);
        Noeud(char operateur, Noeud* gauche, Noeud* droit);
        int hauteur();
        ~Noeud();
};

class Arbre
{
    Noeud *racine;
    public :
        Arbre();
        Arbre(Noeud * N);
        ~Arbre();
        double evaluation();
        double evaluation(Noeud * p);
        void affichageInfixe();
        void affichageInfixe(Noeud * p);
    };

#endif