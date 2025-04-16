#include "Arbre.hpp"

/**
 * Constructeur de la classe Arbre
 **/
Arbre::Arbre()
{
    this->racine = nullptr;
}

/**
 * Constructeur de la classe Arbre avec une expression normale (infixée)
 * @param expr : chaine de caractères représentant l'expression (ex: "5*(3+2)") 
 **/
Arbre::Arbre(const string& expr)
{
    stack <Noeud*> pile;
    string postfixe = infixeVersSuffixe(expr);
    for (char c : postfixe)
    {
        if (isdigit(c))
        {
            double val = c - '0';
            pile.push(new Noeud(val));
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            Noeud* droite = pile.top();
            pile.pop();
            Noeud* gauche = pile.top();
            pile.pop();
            Noeud* op = new Noeud(c, gauche, droite);
            pile.push(op);
        }
    }

    if (!pile.empty())
    {
        this->racine = pile.top();
        pile.pop();
    } 
    else
        this->racine = nullptr;
}

/**
 * Destructeur de la classe Arbre
 **/
Arbre::~Arbre()
{
    if (this->racine != NULL)
        delete this->racine;
}

/**
 * Constructeur par défaut de la classe Noeud
 **/
Noeud::Noeud()
{
    this->type = '\0';
    this->op = '\0';
    this->val = 0;
    this->fg = NULL;
    this->fd = NULL;
}

/**
 * Destructeur de la classe Noeud
 **/
Noeud::~Noeud()
{
    if (this->fg != NULL)
        delete this->fg;
    if (this->fd != NULL)
        delete this->fd;
}

/**
 * Constructeur pour un noeud de type feuille
 * @param valeur : la valeur du noeud
 **/
Noeud::Noeud(double valeur)
{
    this->type = 'f';
    this->val = valeur;
    this->op = '\0';
    this->fg = fd = nullptr;
}

/**
 * Constructeur pour un noeud de type opérateur
 * @param op : l'opérateur
 * @param fg : le fils gauche
 * @param fd : le fils droit
 **/
Noeud::Noeud(char op, Noeud* fg, Noeud* fd) {
    this->type = 'o';
    this->op = op;
    this->val = 0;
    this->fg = fg;
    this->fd = fd;
}

/**
 * Fonction pour évaluer l'arbre
 **/
double Arbre::evaluation()
{
    return evaluation(racine);
}

/**
 * Fonction pour évaluer un noeud de l'arbre
 * @param p : le noeud à évaluer
 **/
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

/**
 * Fonction pour afficher l'arbre en notation infixée
 **/
void Arbre::affichageInfixe()
{
    affichageInfixe(this->racine);
    cout << endl;
}

/**
 * Fonction pour afficher un noeud de l'arbre en notation infixée
 * @param p : le noeud à afficher
 **/
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