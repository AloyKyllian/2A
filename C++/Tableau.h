#include <iostream>
using namespace std;

class Tableau
{
private:
    int *valeurs;
    int nbElem;
    int tailleMax;
    // variables cachées appelées “attributs”
    // accessibles depuis les méthodes de la classe
protected:
    // variables accessibles depuis la classe et ses sous-classes
public:
    Tableau(int * = NULL, int = 0, int = 10);
    Tableau(Tableau &);
    ~Tableau();
    // fonctions qui manipulent les variables cachées
    // appelées “méthodes”
};