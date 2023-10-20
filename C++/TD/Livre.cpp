#include "Livre.h"

Livre::Livre(std::string titre, int annee)
{
    this->titre = titre;
    this->annee = annee;
}

Livre::Livre(Livre &copie)
{
    this->titre = copie.titre;
    this->annee = copie.annee;
}

// Surcharge de l’opérateur d’affichage <<
ostream &operator<<(ostream &out, Livre &l)
{
    cout << "titre" << l.titre << endl;
    cout << "annee" << l.annee << endl;
    return out;
}