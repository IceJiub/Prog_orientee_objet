#include "Pile.hpp"

/**
 * Constructeur de la classe Maillon
 * @param val : la valeur du maillon
 * @param suiv : le maillon suivant
 **/
Maillon::Maillon(double val, Maillon* suiv)
{
    this->valeur = val;
    this->suivant = suiv;
}

/**
 * Constructeur de la classe Pile
 **/
Pile::Pile()
{
    this->sommet = nullptr;
}

/**
 * Destructeur de la classe Pile
 **/
Pile::~Pile() 
{
    while (!vide()) {
        depiler();
    }
}

/**
 * Fonction pour empiler un élément dans la pile
 * @param val : la valeur à empiler
 **/
void Pile::empiler(double val) 
{
    Maillon* n = new Maillon(val, sommet);
    sommet = n;
}

/**
 * Fonction pour dépiler la pile
 * @throws : Erreur si la pile est vide
 **/
void Pile::depiler() 
{
    if (this->vide())
    {
        cerr << "Erreur : Pile vide" << endl;
        return;
    }
    Maillon* tmp = this->sommet;
    sommet = this->sommet->suivant;
    delete tmp;
}

/**
 * Fonction pour vérifier si la pile est vide
 * @return : true si la pile est vide, false sinon
 **/
bool Pile::vide() 
{
    if (this->sommet == nullptr)
        return true;
    return false;
}

/**
 * Fonction pour obtenir la valeur au sommet de la pile
 * @return : la valeur au sommet de la pile
 **/
double Pile::sommetPile() 
{
    if (vide()) {
        cout << "Erreur : Pile vide" << endl;
        return 0;
    }
    return this->sommet->valeur;
}

/**
 * Fonction pour évaluer la priorité des opérateurs
 * @param op : l'opérateur
 * @return : la priorité de l'opérateur (1 pour + et -, 2 pour * et /)
 **/
int priorite(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

/**
 * Fonction pour évaluer une expression postfixée
 * @param expr : la chaîne de caractères représentant l'expression postfixée
 * @return : le résultat de l'évaluation
 **/
double evaluer(const string& expr)
{
    Pile pile;
    for (char c : expr) 
    {
        // Si c'est un chiffre, on le place au sommet de la pile
        if (isdigit(c))
            pile.empiler(c - '0'); // Convertit le caractère en entier
        // Si c'est un opérateur, on dépile les deux dernier éléments de la pile et on leur applique l'opération
        else
        {
            double b = pile.sommetPile();
            pile.depiler();
            double a = pile.sommetPile();
            pile.depiler();
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
    return pile.sommetPile();
}

/**
 * Fonction pour convertir une expression infixée en suffixée (postfixe)
 * @param expr : la chaîne de caractères représentant l'expression infixée
 * @return : la chaîne de caractères représentant l'expression suffixée
 **/
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
            {
                postfixe += pile.sommetPile();
                pile.depiler();
            }
            if (!pile.vide())
                pile.depiler();
        }
        else 
        {
            while (!pile.vide() && priorite(pile.sommetPile()) >= priorite(c))
            {
                postfixe += pile.sommetPile();
                pile.depiler();
            }
            pile.empiler(c);
        }
    }
    while (!pile.vide())
    {
        postfixe += pile.sommetPile();
        pile.depiler();
    }    
    return postfixe;
}