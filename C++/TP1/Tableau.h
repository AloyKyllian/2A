#ifndef Tableau_H
#define Tableau_H

#include "Entree.h"

class Tableau
{

public:
    Entree *entrees;
    int tailleTotale;
    int nbelem;
    Tableau(int taille);
    ~Tableau();
    Tableau(const Tableau &autre);
    void Afficher();
    void Ajouter(std::string nom, std::string numero);
    void Supprimer(std::string nom, std::string numero);
    void Supprimer(std::string nom);
    int GetNbElem();
    int GetTaille();
    friend std::ostream &operator<<(std::ostream &out, Tableau &tableau);
    bool operator==(Tableau &autre);
    Tableau operator+(Tableau &autre);
    Tableau &operator+=(Tableau &autre);
    Entree &operator[](std::string nom);
    bool operator/(std::string nom);
};

#endif
