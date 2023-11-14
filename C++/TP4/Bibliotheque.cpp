#include "Bibliotheque.h"
#include <iostream>

// Méthode pour ajouter un document à la bibliothèque
void Bibliotheque::ajouterDocument(Document *document)
{
    documents.push_back(document);
}

// Méthode pour rechercher un document par son titre
Document *Bibliotheque::rechercherParTitre(const std::string &titre)
{
    for (Document *doc : documents)
    {
        if (doc->gettitre() == titre)
        {
            return doc;
        }
    }
    return nullptr;
}

// Méthode pour afficher le contenu de la bibliothèque
void Bibliotheque::afficherContenu() const
{
    std::cout << "Contenu de la bibliothèque:\n";
    for (Document *doc : documents)
    {
        doc->afficher();
        std::cout << "------------------------\n";
    }
}
