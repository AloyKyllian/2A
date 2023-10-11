#include <iostream>
#include "compte.h"
using namespace std;

Compte::Compte()
{
    this->solde = 0;
};

void Compte::depot(float depot)
{
    this->solde = this->solde + depot;
}

void Compte::retrait(float retrait)
{
    this->solde = this->solde - retrait;
}

void Compte::afficher_solde()
{
    cout << this->solde;
}

float Compte::getSolde()
{
    return (this->solde);
}

void Compte::virement(Compte &compte, float argent)
{
    compte.depot(argent);
    this->solde = this->solde - argent;
}

int main()
{
    Compte compte1;
    Compte compte2;
    float solde;
    compte1.depot(102);
    cout << endl;
    compte1.afficher_solde();
    cout << endl;
    compte1.retrait(50);
    solde = compte1.getSolde();
    cout << "solde = " << solde;
    compte1.virement(compte2, solde);
    cout << endl;
    compte1.afficher_solde();
    cout << endl;
    compte2.afficher_solde();
}
