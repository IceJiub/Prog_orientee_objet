#include <iostream>
#include "Point.hpp"
#include "CollectionPoints.hpp"
using namespace std;

Col_Points::Col_Points(int cap)
{
    this->cap = cap;
    this->nbp = 0;
    this->tab = new Point[cap];
}

Col_Points::Col_Points()
{
    this->cap = 100;
    this->nbp = 0;
    this->tab = new Point[cap];
}

Col_Points::Col_Points(const Col_Points &c)
{
    this->cap = c.cap;
    this->nbp = c.nbp;
    this->tab = new Point[this->cap];
    for (int i = 0 ; i < this->nbp ; i++)
        this->tab[i] = c.tab[i];
}

Col_Points::Col_Points(const Col_Points &A, const Col_Points &B)
{
    this->cap = A.cap;
    this->nbp = 0;
    this->tab = new Point[this->cap];
    for (int i = 0 ; i < A.nbp ; i++)
    {
        this->tab[this->nbp] = A.tab[i];
        this->nbp++;
    }
    for (int i = 0 ; i < B.nbp ; i++)
    {
        if (!this->present(B.tab[i]))
        {
            this->tab[this->nbp] = B.tab[i];
            this->nbp++;
        }
    }
}

Col_Points::~Col_Points()
{
    delete [] tab;
}

int Col_Points::getCap()
{
    return this->cap;
}

int Col_Points::getNbp()
{
    return this->nbp;
}

void Col_Points::afficher()
{
    cout << "Collection de points : " << endl;
    for (int i = 0 ; i < this->nbp ; i++)
        this->tab[i].afficher();
}

bool Col_Points::present(const Point &p)
{
    for (int i = 0 ; i < this->nbp ; i++)
        if (this->tab[i].distance(p) == 0)
            return true;
    return false;
}

bool Col_Points::ajouter(const Point &p)
{
    if (this->nbp == this->cap)
        return false;
    if (this->present(p))
        return false;
    this->tab[this->nbp] = p;
    this->nbp++;
    return true;
}

bool Col_Points::supprimer(const Point &p)
{
    if (!this->present(p))
        return false;
    for (int i = 0 ; i < this->nbp ; i++)
        if (this->tab[i].distance(p) == 0)
        {
            for (int j = i ; j < this->nbp-1 ; j++)
                this->tab[j] = this->tab[j+1];
            this->nbp--;
            return true;
        }
    return false;
}

bool Col_Points::ajouter_bis(const Point &p)
{
    if (this->nbp == this->cap)
    {
        Point *tab = new Point[this->cap*2];
        for (int i = 0 ; i < this->nbp ; i++)
            tab[i] = this->tab[i];
        delete [] this->tab;
        this->tab = tab;
        this->cap *= 2;
    }
    if (this->present(p))
        return false;
    this->tab[this->nbp] = p;
    this->nbp++;
    return true;
}

void Col_Points::ajouterTab(const Point *tab, int taille)
{
    for (int i = 0 ; i < taille ; i++)
        this->ajouter_bis(tab[i]);
}

void Col_Points::intersection(const Col_Points &A, Col_Points &B)
{
    for (int i = 0 ; i < this->nbp ; i++)
        if (this->present(A.tab[i]))
            B.ajouter_bis(this->tab[i]);
}

Point * Col_Points::resultat()
{
    Point *tab = new Point[5];
    // Initialisation du tableau
    for (int i = 0 ; i < 5 ; i++)
        tab[i] = this->tab[0];

    // Recherche des points extrêmes
    for (int i = 0 ; i < this->nbp ; i++)
    {
        if (this->tab[i].getX() < tab[0].getX())
            tab[0] = this->tab[i];
        if (this->tab[i].getX() > tab[1].getX())
            tab[1] = this->tab[i];
        if (this->tab[i].getY() < tab[2].getY())
            tab[2] = this->tab[i];
        if (this->tab[i].getY() > tab[3].getY())
            tab[3] = this->tab[i];
    }

    // Calcul du barycentre
    double x = 0.0, y = 0.0;
    for (int i = 0 ; i < this->nbp ; i++)
    {
        x += this->tab[i].getX();
        y += this->tab[i].getY();
    }
    tab[4] = Point(x/this->nbp, y/this->nbp);

    return tab;
}

void Col_Points::afficherResultat()
{
    Point *tab = this->resultat();
    cout << "Resultat : " << endl;
    cout << "Point ayant la plus petite abscisse : " , tab[0].afficher();
    cout << "Point ayant la plus grande abscisse: " , tab[1].afficher();
    cout << "Point ayant la plus petite ordonnée : " , tab[2].afficher();
    cout << "Point ayant la plus grande ordonnée : " , tab[3].afficher();
    cout << "Barycentre : " , tab[4].afficher();
    delete [] tab;
}