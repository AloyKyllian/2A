#include "Document.h"

// Constructeur avec paramètres
Document::Document(std::string &t, std::string resume, std::string auteur)
    : titre(t), resume(new std::string(resume)), auteur(auteur) {}

// Constructeur de copie
Document::Document(const Document &other)
    : titre(other.titre), resume(new std::string(*(other.resume))), auteur(other.auteur) {}

// Méthode pour afficher le document
void Document::afficher()
{
    std::cout << "Titre: " << titre << "\nRésumé: " << *resume << "\nAuteur: " << auteur << std::endl;
}

// Méthode pour cloner le document
Document Document::clone()
{
    return Document(*this);
}

Document &Document::operator=(const Document &other)
{
    if (this != &other)
    {
        titre = other.titre;
        delete resume;
        resume = new std::string(*(other.resume));
        auteur = other.auteur;
    }
    return *this;
}

std::string Document::gettitre()
{
    return titre;
}