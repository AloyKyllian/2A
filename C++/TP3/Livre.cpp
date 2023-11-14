#include "Livre.h"
#include <iostream>

// Constructeur par défaut
// Livre::Livre() : Document(), editeur(""), anneeParution(0) {}

// Constructeur avec paramètres
Livre::Livre(std::string &titre, const std::string &resume, const std::string &auteur,
             const std::string &editeur, int anneeParution)
    : Document(titre, resume, auteur), editeur(editeur), anneeParution(anneeParution) {}

// Constructeur de copie
Livre::Livre(const Livre &other)
    : Document(other), editeur(other.editeur), anneeParution(other.anneeParution) {}

// Redéfinition de la méthode afficher
void Livre::afficher()
{
    // Appeler la méthode afficher de la classe de base
    Document::afficher();

    // Ajouter les informations spécifiques aux livres
    std::cout << "Éditeur: " << editeur << "\nAnnée de parution: " << anneeParution << std::endl;
}

// Redéfinition de la méthode clone
Livre Livre::clone()
{
    return Livre(*this);
}

Livre &Livre::operator=(const Livre &other)
{
    if (this != &other)
    {
        // Appel de l'opérateur d'affectation de la classe de base
        Document::operator=(other);
        editeur = other.editeur;
        anneeParution = other.anneeParution;
    }
    return *this;
}