#ifndef POINT_HPP
#define POINT_HPP

class Point
{
    private:
        double x, y;
    public:
        Point();
        Point(double x, double y);
        void afficher();
        double distance(Point &p);
        void saisir();
        
};

void saisir(Point *p, int taille);
Point * saisir_points(int &n);

#endif