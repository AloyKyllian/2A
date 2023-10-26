#ifndef ENTREE_H
#define ENTREE_H

#include <string>
#include <iostream>

class Entree
{
public:
    std::string Nom;
    std::string NumeroTelephone;

    // Constructeur de la classe Entree
    Entree(std::string nom = "", std::string numero = "");

    // Méthode d'affichage pour Entree
    void Afficher();

    // Opérateur de sortie (<<) pour afficher une entrée
    friend std::ostream &operator<<(std::ostream &out, const Entree &entree);

    // Opérateur d'égalité (==) pour comparer deux entrées
    bool operator==(const Entree &autre) const;

    bool operator!=(const Entree &autre) const;
};

#endif
