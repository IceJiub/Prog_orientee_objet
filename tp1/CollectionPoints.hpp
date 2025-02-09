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
        ~Col_Points();
        int getCap();
        int getNbp();
        bool present(const Point &p);
        bool ajouter(const Point &p);
        bool supprimer(const Point &p);
        bool ajouter_bis(const Point &p);
};

#endif