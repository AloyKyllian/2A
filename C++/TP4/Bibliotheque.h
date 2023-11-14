#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <list>
using namespace std;
#include "Document.h" // Inclure la classe Document (ou la classe de base pour les articles et livres)
#include "Livre.h"
#include "Article.h"

class Bibliotheque
{
public:
    // Méthode pour ajouter un document à la bibliothèque
    void ajouterDocument(Document *document);

    // Méthode pour rechercher un document par son titre
    Document *rechercherParTitre(const std::string &titre);

    // Méthode pour afficher le contenu de la bibliothèque
    void afficherContenu() const;

private:
    list<Document *> documents;
};

#endif // BIBLIOTHEQUE_H
