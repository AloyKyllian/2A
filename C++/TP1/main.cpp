#include <iostream>
#include "Agenda.cpp"
#include "Tableau.cpp"
#include "Entree.cpp"

int main()
{
    // Création d'entrees pour tester
    Entree entree1("Alice", "123456");
    Entree entree2("Bob", "789012");
    Entree entree3("Charlie", "456789");

    // Création d'agendas
    Agenda agenda1(10);
    Agenda agenda2(5);

    // Ajout d'entrees aux agendas
    agenda1.Ajouter(entree1.Nom, entree1.NumeroTelephone);
    agenda1.Ajouter(entree2.Nom, entree2.NumeroTelephone);
    agenda2.Ajouter(entree2.Nom, entree2.NumeroTelephone);
    agenda2.Ajouter(entree3.Nom, entree3.NumeroTelephone);

    // Test des opérateurs et des méthodes
    std::cout << "Agenda 1 :" << std::endl;
    std::cout << agenda1 << std::endl;

    std::cout << "Agenda 2 :" << std::endl;
    std::cout << agenda2 << std::endl;

    std::cout << "Comparaison d'agendas : " << (agenda1 == agenda2 ? "Ils sont identiques." : "Ils sont différents.") << std::endl;

    Entree entreeTrouvee = agenda1["Alice"];
    std::cout << "Recherche dans Agenda 1 : " << entreeTrouvee << std::endl;

    agenda1 += agenda2;
    std::cout << "Concaténation de Agenda 1 et Agenda 2 :" << std::endl;
    std::cout << agenda1 << std::endl;

    std::cout << "Noms commençant par 'B' dans Agenda 1 :" << std::endl;
    agenda1('B');

    agenda1 -= "Alice";
    std::cout << "Suppression de l'entrée 'Alice' dans Agenda 1 :" << std::endl;
    std::cout << agenda1 << std::endl;

    return 0;
}
