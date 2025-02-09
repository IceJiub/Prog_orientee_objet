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
        if (this->present(p))
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