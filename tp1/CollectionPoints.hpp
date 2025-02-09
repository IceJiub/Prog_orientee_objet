#ifndef COL_POINT_HPP
#define COL_POINT_HPP
#include "Point.hpp"

class Col_Points
{
    Point * tab;
    int cap;
    int nbp;

    public:
        Col_Points(int cap);
        Col_Points();
        Col_Points(const Col_Points &c);
        ~Col_Points();
        int getCap();
        int getNbp();
        void afficher();
        bool present(const Point &p);
        bool ajouter(const Point &p);
        bool supprimer(const Point &p);
        bool ajouter_bis(const Point &p);
        void ajouterTab(const Point *tab, int taille);
};

#endif