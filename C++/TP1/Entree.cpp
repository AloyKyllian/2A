#include "Entree.h"

// Définition du constructeur de la classe Entree
Entree::Entree(std::string nom, std::string numero)
    : Nom(nom), NumeroTelephone(numero) {}

// Définition de la méthode d'affichage pour Entree
void Entree::Afficher()
{
    std::cout << "Nom : " << this->Nom << std::endl;
    std::cout << "Numéro de téléphone : " << this->NumeroTelephone << std::endl;
}

std::ostream &operator<<(std::ostream &out, Entree &entree)
{
    out << "Nom : " << entree.Nom << std::endl;
    out << "Numéro de téléphone : " << entree.NumeroTelephone << std::endl;
    return out;
}

bool Entree::operator==(Entree &autre)
{
    return (Nom == autre.Nom && NumeroTelephone == autre.NumeroTelephone);
}

bool Entree::operator!=(Entree &autre)
{
    return !(*this == autre);
}