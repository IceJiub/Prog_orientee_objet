#include <iostream>
#include "col_entiers.hpp"
using namespace std;

int main()
{
    Col_Entiers collection(10);
    collection.add(1);
    collection.add(2);
    collection.add(3);
    collection.add(4);
    collection.add(5);
    collection.affichage();
}