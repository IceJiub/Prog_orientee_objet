#ifndef COL_ENTIERS_HPP
#define COL_ENTIERS_HPP

class Col_Entiers
{
    int * T;
    int nbe;
    int taille;
    
    public:
        Col_Entiers(int taille);
        Col_Entiers(Col_Entiers &c);
        void add(int n);
        void affichage();
};

#endif