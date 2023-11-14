#include "Article.h"
#include <iostream>

// Constructeur par défaut
// Article::Article() : Document(), nomRevue(""), editeur(""), numeroEdition(0) {}

// Constructeur avec paramètres
Article::Article(std::string &titre, const std::string &resume, const std::string &auteur,
                 const std::string &nomRevue, const std::string &editeur, int numeroEdition)
    : Document(titre, resume, auteur), nomRevue(nomRevue), editeur(editeur), numeroEdition(numeroEdition) {}

// Constructeur de copie
Article::Article(const Article &other)
    : Document(other), nomRevue(other.nomRevue), editeur(other.editeur), numeroEdition(other.numeroEdition) {}

// Redéfinition de la méthode afficher
void Article::afficher()
{
    // Appeler la méthode afficher de la classe de base
    Document::afficher();

    // Ajouter les informations spécifiques aux articles
    std::cout << "Nom de la revue: " << nomRevue << "\nÉditeur: " << editeur
              << "\nNuméro d'édition: " << numeroEdition << std::endl;
}

// Redéfinition de la méthode clone
Article Article::clone()
{
    return Article(*this);
}

Article &Article::operator=(const Article &other)
{
    if (this != &other)
    {
        // Appel de l'opérateur d'affectation de la classe de base
        Document::operator=(other);
        nomRevue = other.nomRevue;
        editeur = other.editeur;
        numeroEdition = other.numeroEdition;
    }
    return *this;
}