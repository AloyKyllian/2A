#include "Livre.h"

class Biblio
{
private:
    Livre *tableau_livre;
    int taillemax;
    int nbrelement;

public:
    Biblio(int = 10);
    Biblio(Biblio &);
    ~Biblio();
    void ajouter_livre(Livre &);
    Biblio &operator=(Biblio &);
    friend ostream &operator<<(ostream &out, Biblio &l);
};
