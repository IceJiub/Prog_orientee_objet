#ifndef MAILLON_HPP
#define MAILLON_HPP

class Maillon {
    int Info;
    Maillon * suivant;
    friend class Liste; 
    public:
        Maillon();
        Maillon(int n);
        Maillon(int n, Maillon * m);
};

#endif