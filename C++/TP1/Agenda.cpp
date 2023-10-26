// #include "Agenda.h"
// #include <iostream>

// // Constructeur de la classe Agenda
// Agenda::Agenda(int taille) : tableau(taille) {}

// // Constructeur par copie
// Agenda::Agenda(Agenda &autre) : tableau(autre.tableau) {}

// // Méthode de concaténation d'agendas
// void Agenda::Concat(Agenda &autre)
// {
//     // Obtenez le nombre d'éléments dans l'autre agenda
//     int nbElemAutre = autre.tableau.GetNbElem();

//     // Vérifiez si le tableau actuel a suffisamment d'espace pour contenir les éléments de l'autre agenda
//     if (this->tableau.GetNbElem() + nbElemAutre <= this->tableau.GetTaille())
//     {
//         // Copiez les éléments de l'autre tableau dans celui-ci
//         for (int i = 0; i < nbElemAutre; i++)
//         {
//             Ajouter(autre.tableau.entrees[i].Nom, autre.tableau.entrees[i].NumeroTelephone);
//         }
//     }
//     else
//     {
//         // Gérer l'erreur de capacité insuffisante
//         std::cout << "Erreur : Capacité maximale atteinte lors de la concaténation." << std::endl;
//     }
// }

// // Ajouter une entrée à l'agenda
// void Agenda::Ajouter(std::string nom, std::string numero)
// {
//     tableau.Ajouter(nom, numero);
// }

// // Supprimer une entrée par nom et numéro
// void Agenda::Supprimer(std::string nom, std::string numero)
// {
//     tableau.Supprimer(nom, numero);
// }

// // Supprimer une entrée par nom
// void Agenda::Supprimer(std::string nom)
// {
//     tableau.Supprimer(nom);
// }

// // Méthode d'affichage de l'agenda
// void Agenda::Afficher()
// {
//     std::cout << "Agenda : " << std::endl;
//     this->tableau.Afficher();
// }

#include "Agenda.h"

// Constructeur
Agenda::Agenda(int taille)
{
    tableau = new Tableau(taille);
}

// Constructeur par copie
Agenda::Agenda(Agenda &autre)
{
    tableau = new Tableau(*(autre.tableau));
}

// Destructeur
Agenda::~Agenda()
{
    delete tableau;
}

// Méthode de concaténation d'agendas
void Agenda::Concat(Agenda &autre)
{
    int nbElemAutre = autre.tableau->GetNbElem();
    int tailleTotaleActuelle = tableau->GetTaille();

    if (tableau->GetNbElem() + nbElemAutre <= tailleTotaleActuelle)
    {
        for (int i = 0; i < nbElemAutre; i++)
        {
            const Entree &entreeAutre = autre.tableau->entrees[i];
            tableau->Ajouter(entreeAutre.Nom, entreeAutre.NumeroTelephone);
        }
    }
    else
    {
        std::cout << "Erreur : Capacité maximale atteinte lors de la concaténation." << std::endl;
    }
}

// Ajouter une entrée à l'agenda
void Agenda::Ajouter(std::string nom, std::string numero)
{
    tableau->Ajouter(nom, numero);
}

// Supprimer une entrée par nom et numéro
void Agenda::Supprimer(std::string nom, std::string numero)
{
    tableau->Supprimer(nom, numero);
}

// Supprimer une entrée par nom
void Agenda::Supprimer(std::string nom)
{
    tableau->Supprimer(nom);
}

// Méthode d'affichage de l'agenda
void Agenda::Afficher()
{
    tableau->Afficher();
}
// Opérateur de sortie (<<) pour afficher un agenda
std::ostream &operator<<(std::ostream &out, Agenda &agenda)
{
    out << *agenda.tableau;
    return out;
}

// Opérateur d'addition-assignation (+=) pour ajouter un nom et un numéro de téléphone
Agenda &Agenda::operator+=(Entree &entree)
{
    tableau->Ajouter(entree.Nom, entree.NumeroTelephone);
    return *this;
}

// Opérateur d'assignation (=) pour affecter un agenda à un autre
Agenda &Agenda::operator=(Agenda &autre)
{
    if (this != &autre)
    {
        delete tableau;
        tableau = new Tableau(*(autre.tableau));
    }
    return *this;
}

// Opérateur d'addition (+) pour concaténer deux agendas
Agenda Agenda::operator+(Agenda &autre)
{
    Agenda resultat(tableau->GetTaille() + autre.tableau->GetTaille());
    *resultat.tableau = *tableau;
    *resultat.tableau += *autre.tableau;
    return resultat;
}

// Opérateur d'addition-assignation (+=) pour concaténer un agenda à un autre
Agenda &Agenda::operator+=(Agenda &autre)
{
    *tableau += *autre.tableau;
    return *this;
}

// Opérateur [] pour retourner la première occurrence d'un nom
Entree &Agenda::operator[](std::string nom)
{
    return (*tableau)[nom];
}

// Opérateur de soustraction-assignation (-=) pour supprimer toutes les occurrences d'un nom
Agenda &Agenda::operator-=(std::string nom)
{
    tableau->Supprimer(nom);
    return *this;
}

// Opérateur d'égalité (==) pour comparer deux agendas
bool Agenda::operator==(Agenda &autre)
{
    return *tableau == *(autre.tableau);
}

// Opérateur / pour tester si un nom est dans l'agenda (nom / Agenda)
bool Agenda::operator/(std::string nom)
{
    return (*tableau / nom);
}

// Opérateur () pour afficher les noms commençant par une lettre donnée
void Agenda::operator()(char lettre)
{
    for (int i = 0; i < tableau->GetNbElem(); i++)
    {
        if (tableau->entrees[i].Nom[0] == lettre)
        {
            std::cout << "Nom : " << tableau->entrees[i].Nom << std::endl;
            std::cout << "Numéro de téléphone : " << tableau->entrees[i].NumeroTelephone << std::endl;
        }
    }
}