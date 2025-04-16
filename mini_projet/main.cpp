#include "Pile.hpp"
#include "Arbre.hpp"

int main() {

    // Test de la fonction evaluer (question 1)
    // string expr;
    // cout << "Entrez une expression suffixé (ex: 123+*): ";
    // cin >> expr;
    // double resultat = evaluer(expr);
    // cout << "Resultat: " << resultat << endl;

    // Test de la fonction infixeVersSuffixe (question 2)
    // string expr;
    // cout << "Entrez une expression infixe (ex: 5*(3+2)): ";
    // cin >> expr;
    // string postfixe = infixeVersSuffixe(expr);
    // cout << "Expression suffixe: " << postfixe << endl;
    // double resultat = evaluer(postfixe);
    // cout << "Resultat: " << resultat << endl;

    // Test fonction evaluation et affichageInfixe (question 3)
    string expr;
    cout << "Entrez une expression infixe (ex: 5*(3+2)): ";
    cin >> expr;
    Arbre monArbre(expr);
    monArbre.affichageInfixe();
    cout << "Résultat : " << monArbre.evaluation() << endl;

    return 0;
}