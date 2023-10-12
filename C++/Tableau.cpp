#include "Tableau.h"

Tableau::Tableau(int *valeurs, int nbElem, int tailleMax)
{
    this->valeurs = valeurs;
    this->nbElem = nbElem;
    this->tailleMax = tailleMax;
};

Tableau::Tableau(Tableau &copie)
{
    this->valeurs = copie.valeurs;
    this->nbElem = copie.nbElem;
    this->tailleMax = copie.tailleMax;
};

Tableau::~Tableau()
{
    delete valeurs, nbElem, tailleMax; // appel de ~Texte()
}

int main()
{
    int p[20];
    for (int i = 0; i < 6; i++)
    {
        p[i] = i;
    }
    Tableau tab1 = Tableau(p, 6, 20);
    tab1.~Tableau();
}