#include "Biblio.h"

int main()
{
    cout << "ici";
    Biblio b(6);
    Livre l("salut", 1024);
    b.ajouter_livre(l);

    cout << b;
    cout << "ici";
}