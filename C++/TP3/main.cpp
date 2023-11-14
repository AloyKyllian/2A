#include "Document.cpp"
#include "Livre.cpp"
#include "Article.cpp"

int main()
{
    std::string titre = "Titre du document";
    // Test de la classe Document
    Document doc1(titre, "Ceci est un résumé.", "Auteur du document");

    // Affichage du document
    std::cout << "Document original:\n";
    doc1.afficher();

    // Création d'une copie du document
    Document doc2 = doc1.clone();

    // Affichage de la copie
    std::cout << "\nCopie du document:\n";
    doc2.afficher();

    // Test de la classe Livre
    Livre livre1(titre, "Ceci est un résumé.", "Auteur du livre", "Éditeur du livre", 2022);

    // Affichage du livre
    std::cout << "\nLivre original:\n";
    livre1.afficher();

    // Création d'une copie du livre
    Livre livre2 = livre1.clone();

    // Affichage de la copie
    std::cout << "\nCopie du livre:\n";
    livre2.afficher();

    // Test de la classe Article
    Article article1(titre, "Ceci est un résumé.", "Auteur de l'article",
                     "Nom de la revue", "Éditeur de l'article", 123);

    // Affichage de l'article
    std::cout << "\nArticle original:\n";
    article1.afficher();

    // Création d'une copie de l'article
    Article article2 = article1.clone();

    // Affichage de la copie
    std::cout << "\nCopie de l'article:\n";
    article2.afficher();

    // Test de l'opérateur d'affectation pour Document
    Document doc3 = doc1;
    std::cout << "\nDocument après opérateur d'affectation:\n";
    doc3.afficher();

    // Test de l'opérateur d'affectation pour Livre
    Livre livre3 = livre1;
    std::cout << "\nLivre après opérateur d'affectation:\n";
    livre3.afficher();

    // Test de l'opérateur d'affectation pour Article
    Article article3 = article1;
    std::cout << "\nArticle après opérateur d'affectation:\n";
    article3.afficher();

    return 0;
}
