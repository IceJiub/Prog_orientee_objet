#include "Pile.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Maillon::Maillon(double val, Maillon* suiv)
{
    this->valeur = val;
    this->suivant = suiv;
}

Pile::Pile()
{
    this->sommet = nullptr;
}

Pile::~Pile() 
{
    while (!vide()) {
        depiler();
    }
}

void Pile::empiler(double val) 
{
    Maillon* n = new Maillon(val, sommet);
    sommet = n;
}

double Pile::depiler() 
{
    if (this->vide())
    {
        cout << "Erreur : Pile vide" << endl;
        return 0;
    }
    double val = this->sommet->valeur;
    Maillon* tmp = this->sommet;
    sommet = this->sommet->suivant;
    delete tmp;
    return val;
}

bool Pile::vide() const 
{
    if (this->sommet == nullptr)
        return true;
    return false;
}

double Pile::sommetPile() const 
{
    if (vide()) {
        cout << "Erreur : Pile vide" << endl;
        return 0;
    }
    return this->sommet->valeur;
}

int priorite(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // pour les parenthèses ou opérateurs inconnus
}

double evaluer(const string& expr)
{
    Pile pile;
    for (char c : expr) 
    {
        // Si c'est un chiffre, on le place au sommet de la pile
        if (isdigit(c))
            pile.empiler(c - '0');
        // Si c'est un opérateur, on dépile les deux dernier éléments de la pile et on leur applique l'opération
        else
        {
            double b = pile.depiler();
            double a = pile.depiler();
            switch (c)
            {
                case '+': pile.empiler(a + b); break;
                case '-': pile.empiler(a - b); break;
                case '*': pile.empiler(a * b); break;
                case '/': pile.empiler(a / b); break;
                default: cout << "Erreur : Operateur inconnu" << endl; return 0;
            }
        }
    }
    return pile.depiler();
}

string infixeVersSuffixe(const string& expr)
{
    Pile pile;
    string postfixe;
    for (char c : expr)
    {
        if (isdigit(c))
            postfixe += c;
        else if (c == '(')
            pile.empiler(c);
        else if (c == ')')
        {
            while (!pile.vide() && pile.sommetPile() != '(')
                postfixe += pile.depiler();
            pile.depiler();
        }
        else 
        {
            while (!pile.vide() && priorite(pile.sommetPile()) >= priorite(c))
                postfixe += pile.depiler();
            pile.empiler(c);
        }
    }
    while (!pile.vide())
        postfixe += pile.depiler();
    return postfixe;
}