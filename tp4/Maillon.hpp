#ifndef MAILLON_HPP
#define MAILLON_HPP

class Maillon {
    int Info;
    Maillon * suivant;
    
    public:
        Maillon();
        Maillon(int n);
        Maillon(int n, Maillon * m);
        friend class Liste;
        friend class Liste_Rapide;
        int getInfo();
        void setInfo(int n);
};

#endif