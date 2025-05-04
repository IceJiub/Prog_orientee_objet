#ifndef ARBRE_HPP
#define ARBRE_HPP
#include "Pile.hpp"
#include <string>
#include <iostream>
#include <stack>
using namespace std;

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
        ~Noeud();
};

class Arbre
{
    Noeud *racine;
    public :
        Arbre();
        Arbre(const string& expr);
        ~Arbre();
        double evaluation();
        double evaluation(Noeud * p);
        void affichageInfixe();
        void affichageInfixe(Noeud * p);
    };

#endif