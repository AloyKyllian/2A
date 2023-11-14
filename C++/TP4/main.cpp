#include "Bibliotheque.cpp"
#include "Document.cpp"
#include "Livre.cpp"
#include "Article.cpp"
int main()
{
    // Création d'une bibliothèque
    Bibliotheque biblio;
    std::string titre = "Titre du livre";
    // Ajout de documents à la bibliothèque
    Document *livre1 = new Livre(titre, "Ceci est un résumé.", "Auteur du livre", "Éditeur du livre", 2022);
    biblio.ajouterDocument(livre1);
    std::string titre2 = "Titre de l'article";
    Document *article1 = new Article(titre2, "Ceci est un résumé. d'article", "Auteur de l'article",
                                     "Nom de la revue", "Éditeur de l'article", 123);
    biblio.ajouterDocument(article1);

    // Affichage du contenu de la bibliothèque
    biblio.afficherContenu();

    // Recherche d'un document par titre
    std::string titreRecherche = "Titre de l'article";
    Document *docTrouve = biblio.rechercherParTitre(titreRecherche);

    if (docTrouve != nullptr)
    {
        std::cout << "\nDocument trouvé par titre:\n";
        docTrouve->afficher();
    }
    else
    {
        std::cout << "\nDocument non trouvé par titre.\n";
    }
    return 0;
}
