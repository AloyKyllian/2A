#ifndef LIVRE_H
#define LIVRE_H

#include "Document.h" // Inclure la classe de base

class Livre : public Document
{
public:
    Livre(std::string &titre, const std::string &resume, const std::string &auteur,
          const std::string &editeur, int anneeParution);
    Livre(const Livre &other);

    // Redéfinition des méthodes de la classe de base
    void afficher();
    Livre clone();
    Livre &operator=(const Livre &other);

private:
    std::string editeur;
    int anneeParution;
};

#endif // LIVRE_H
