#ifndef ARTICLE_H
#define ARTICLE_H

#include "Document.h"

class Article : public Document
{
public:
    Article(std::string &titre, const std::string &resume, const std::string &auteur,
            const std::string &nomRevue, const std::string &editeur, int numeroEdition);
    Article(const Article &other);

    // Redéfinition des méthodes de la classe de base
    void afficher();
    Article clone();
    Article &operator=(const Article &other);

private:
    std::string nomRevue;
    std::string editeur;
    int numeroEdition;
};

#endif // ARTICLE_H
