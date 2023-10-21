#include "Biblio.h"

Biblio::Biblio(int taille)
{
    this->taillemax = taille;
    this->nbrelement = 0;
    this->tableau_livre = new Livre[this->taillemax];
}

Biblio::Biblio(Biblio &copie)
{
    this->nbrelement = copie.nbrelement;
    this->taillemax = copie.taillemax;
    this->tableau_livre = new Livre[this->taillemax];
    for (int i = 0; i < copie.nbrelement; i++)
    {
        this->tableau_livre[i] = copie.tableau_livre[i];
    }
}

Biblio::~Biblio()
{
    delete[] this->tableau_livre;
}

Biblio &Biblio::operator=(Biblio &b)
{
    if (this != &b)
    {
        this->nbrelement = b.nbrelement;
        this->taillemax = b.taillemax;
        delete[] this->tableau_livre;
        this->tableau_livre = new Livre[b.taillemax];
        for (int i = 0; i < this->nbrelement; i++)
        {
            this->tableau_livre[i] = b.tableau_livre[i];
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, Biblio &l)
{
    out << "taille" << l.taillemax << endl;
    out << "nbr d'element" << l.nbrelement << endl;
    for (int i = 0; i < l.nbrelement; i++)
    {
        out << l.tableau_livre[i] << endl;
    }
    return out;
}

void Biblio::ajouter_livre(Livre &l)
{
    this->tableau_livre[this->nbrelement] = l;
    this->nbrelement++;
}