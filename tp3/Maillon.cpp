#include "Maillon.hpp"
#include "Liste.hpp"
#include <iostream>
using namespace std;

Maillon::Maillon()
{
    this->Info = 0;
    this->suivant = NULL;
}

Maillon::Maillon(int n)
{
    this->Info = n;
    this->suivant = NULL;
}

Maillon::Maillon(int n, Maillon * m)
{
    this->Info = n;
    this->suivant = m;
}