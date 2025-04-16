#ifndef PILE_HPP
#define PILE_HPP
#include <string>
#include <iostream>
using namespace std;

class Maillon
{
    double valeur;
    Maillon* suivant;
    friend class Pile; 
    public:
    Maillon(double val, Maillon* suiv);
};

class Pile
{
    private:
        Maillon* sommet;

    public:
        Pile();
        ~Pile();

        void empiler(double val);
        void depiler();
        bool vide();
        double sommetPile();
};

int priorite(char op);
double evaluer(const string& expr);
string infixeVersSuffixe(const string& expr);

#endif