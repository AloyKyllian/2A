#ifndef ENTREE_H
#define ENTREE_H

#include <string>
#include <iostream>

class Entree
{
public:
    std::string Nom;
    std::string NumeroTelephone;

    Entree(std::string nom = "", std::string numero = "");
    void Afficher();
    friend std::ostream &operator<<(std::ostream &out, Entree &entree);
    bool operator==(Entree &autre);
    bool operator!=(Entree &autre);
};

#endif
