#ifndef LISTE_HPP
#define LISTE_HPP

class Liste {
    Maillon * tete;
    public :
        Liste();
        Liste(int *tab, int nb);
        ~Liste();
        void ajout_tete(int x);
        void ajout_queue(int x);
        void afficher();
};

#endif