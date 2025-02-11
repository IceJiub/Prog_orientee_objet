#ifndef LISTE_HPP
#define LISTE_HPP

class Liste {
    Maillon * tete;
    public :
        Liste();
        Liste(int *tab, int nb);
        ~Liste();
        Maillon * getTete();
        void ajout_tete(int x);
        void ajout_queue(int x);
        void afficher();
        void afficher_Rec(Maillon *m);
        void afficher_Inverse(Maillon *m);
        int cardinal();
        bool chercher(int x);
        int Nb_Occurences(int x);
};

#endif