// #ifndef AGENDA_H
// #define AGENDA_H

// #include "Tableau.h"

// class Agenda
// {
// private:
//     Tableau tableau;

// public:
//     // Constructeur
//     Agenda(int taille);

//     // Constructeur par copie
//     Agenda(Agenda &autre);

//     // Méthode de concaténation d'agendas
//     void Concat(Agenda &autre);

//     // Ajouter une entrée à l'agenda
//     void Ajouter(std::string nom, std::string numero);

//     // Supprimer une entrée par nom et numéro
//     void Supprimer(std::string nom, std::string numero);

//     // Supprimer une entrée par nom
//     void Supprimer(std::string nom);

//     // Méthode d'affichage de l'agenda
//     void Afficher();
// };

// #endif

#ifndef AGENDA_H
#define AGENDA_H

#include "Tableau.h"

class Agenda
{
private:
    Tableau *tableau; // Pointeur vers la classe Tableau

public:
    // Constructeur
    Agenda(int taille);

    // Constructeur par copie
    Agenda(Agenda &autre);

    // Destructeur
    ~Agenda();

    // Méthode de concaténation d'agendas
    void Concat(Agenda &autre);

    // Ajouter une entrée à l'agenda
    void Ajouter(std::string nom, std::string numero);

    // Supprimer une entrée par nom et numéro
    void Supprimer(std::string nom, std::string numero);

    // Supprimer une entrée par nom
    void Supprimer(std::string nom);

    // Méthode d'affichage de l'agenda
    void Afficher();

    // Opérateur de sortie (<<) pour afficher un agenda
    friend std::ostream &operator<<(std::ostream &out, Agenda &agenda);

    // Opérateur d'addition-assignation (+=) pour ajouter un nom et un numéro de téléphone
    Agenda &operator+=(Entree &entree);

    // Opérateur d'assignation (=) pour affecter un agenda à un autre
    Agenda &operator=(Agenda &autre);

    // Opérateur d'addition (+) pour concaténer deux agendas
    Agenda operator+(Agenda &autre);

    // Opérateur d'addition-assignation (+=) pour concaténer un agenda à un autre
    Agenda &operator+=(Agenda &autre);

    // Opérateur [] pour retourner la première occurrence d'un nom
    Entree &operator[](std::string nom);

    // Opérateur de soustraction-assignation (-=) pour supprimer toutes les occurrences d'un nom
    Agenda &operator-=(std::string nom);

    // Opérateur d'égalité (==) pour comparer deux agendas
    bool operator==(Agenda &autre);

    // Opérateur / pour tester si un nom est dans l'agenda (nom / Agenda)
    bool operator/(std::string nom);

    // Opérateur () pour afficher tous les noms commençant par une lettre donnée
    void operator()(char lettre);
};

#endif