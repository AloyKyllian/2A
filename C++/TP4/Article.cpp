#include "Article.h"
#include <iostream>

Article::Article(std::string &titre, const std::string &resume, const std::string &auteur,
                 const std::string &nomRevue, const std::string &editeur, int numeroEdition)
    : Document(titre, resume, auteur), nomRevue(nomRevue), editeur(editeur), numeroEdition(numeroEdition) {}

Article::Article(const Article &other)
    : Document(other), nomRevue(other.nomRevue), editeur(other.editeur), numeroEdition(other.numeroEdition) {}

void Article::afficher()
{
    Document::afficher();
    std::cout << "Nom de la revue: " << nomRevue << "\nÉditeur: " << editeur
              << "\nNuméro d'édition: " << numeroEdition << std::endl;
}

Article Article::clone()
{
    return Article(*this);
}

Article &Article::operator=(const Article &other)
{
    if (this != &other)
    {
        Document::operator=(other);
        nomRevue = other.nomRevue;
        editeur = other.editeur;
        numeroEdition = other.numeroEdition;
    }
    return *this;
}