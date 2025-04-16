#include "Arbre.hpp"
#include <iostream>
using namespace std;

Arbre::Arbre()
{
    this->racine = nullptr;
}

Arbre::Arbre(Noeud * N)
{
    this->racine = N;
}

Arbre::~Arbre()
{
    if (this->racine != NULL)
        delete this->racine;
}

Noeud::Noeud()
{
    this->type = '\0';
    this->op = '\0';
    this->val = 0;
    this->fg = NULL;
    this->fd = NULL;
}

Noeud::~Noeud()
{
    if (this->fg != NULL)
        delete this->fg;
    if (this->fd != NULL)
        delete this->fd;
}

Noeud::Noeud(double valeur)
{
    this->type = 'f';
    this->val = valeur;
    this->op = '\0';
    this->fg = fd = nullptr;
}

Noeud::Noeud(char op, Noeud* fg, Noeud* fd) {
    this->type = 'o';
    this->op = op;
    this->val = 0;
    this->fg = fg;
    this->fd = fd;
}


void Arbre::detruire()
{
    detruire(racine);
}

void Arbre::detruire(Noeud * p)
{
    if (p != NULL)
    {
        detruire(p -> fg);
        detruire(p -> fd);
        delete p;
    }
}

double Arbre::evaluation()
{
    return evaluation(racine);
}

double Arbre::evaluation(Noeud* p)
{
    if (p == nullptr)
        return 0; // ou lever une erreur

    if (p->type == 'f')
        return p->val;
    else if (p->type == 'o')
    {
        double gauche = evaluation(p->fg);
        double droite = evaluation(p->fd);

        switch (p->op)
        {
            case '+': return gauche + droite;
            case '-': return gauche - droite;
            case '*': return gauche * droite;
            case '/': return droite != 0 ? gauche / droite : 0; // éviter la division par 0
            default:
                cerr << "Opérateur inconnu : " << p->op << endl;
                return 0;
        }
    } 
    else
    {
        cerr << "Type de noeud invalide" << endl;
        return 0;
    }
}

void Arbre::affichageInfixe()
{
    affichageInfixe(racine);
    cout << endl;
}

void Arbre::affichageInfixe(Noeud * p)
{
    if (p == nullptr) return;

    if (p->type == 'f')
        cout << p->val;
    else if (p->type == 'o')
    {
        cout << '(';
        affichageInfixe(p->fg);
        cout << p->op;
        affichageInfixe(p->fd);
        cout << ')';
    }
}
