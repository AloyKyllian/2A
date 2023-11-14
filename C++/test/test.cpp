#include <iostream>
#include <string>

class Document
{
public:
    // Constructeur par défaut
    Document() : titre(""), resume(nullptr), auteur("") {}

    // Constructeur avec paramètres
    Document(const std::string &titre, const std::string &resume, const std::string &auteur)
        : titre(titre), resume(new std::string(resume)), auteur(auteur) {}

    // Constructeur de copie
    Document(const Document &other)
        : titre(other.titre), resume(new std::string(*(other.resume))), auteur(other.auteur) {}

    // Destructeur
    ~Document()
    {
        delete resume;
    }

    // Méthode pour afficher le document
    void afficher() const
    {
        std::cout << "Titre: " << titre << "\nRésumé: " << *resume << "\nAuteur: " << auteur << std::endl;
    }

    // Méthode pour créer un document à partir de ses champs
    void creer(const std::string &titre, const std::string &resume, const std::string &auteur)
    {
        this->titre = titre;
        delete this->resume; // Supprime l'ancien résumé s'il existe
        this->resume = new std::string(resume);
        this->auteur = auteur;
    }

    // Méthode pour cloner le document
    Document clone() const
    {
        return Document(*this);
    }

private:
    std::string titre;
    std::string *resume;
    std::string auteur;
};

int main()
{
    // Test de la classe Document
    Document doc1;
    doc1.creer("Titre du document", "Ceci est un résumé.", "Auteur du document");

    // Affichage du document
    std::cout << "Document original:\n";
    doc1.afficher();

    // Création d'une copie du document
    Document doc2 = doc1.clone();

    // Affichage de la copie
    std::cout << "\nCopie du document:\n";
    doc2.afficher();

    return 0;
}