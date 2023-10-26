#include "Tableau.h"

Tableau::Tableau(int taille) : tailleTotale(taille), entrees(new Entree[taille]), nbelem(0)
{
}

Tableau::~Tableau()
{
    delete[] entrees;
}

Tableau::Tableau(const Tableau &autre)
    : tailleTotale(autre.tailleTotale), entrees(new Entree[autre.tailleTotale]), nbelem(autre.nbelem)
{
    for (int i = 0; i < nbelem; i++)
    {
        this->entrees[i] = autre.entrees[i];
    }
}

void Tableau::Afficher()
{
    for (int i = 0; i < nbelem; i++)
    {
        std::cout << "Entrée " << i + 1 << ":" << std::endl;
        this->entrees[i].Afficher();
    }
}

void Tableau::Ajouter(std::string nom, std::string numero)
{
    if (nbelem < tailleTotale)
    {
        this->entrees[nbelem++] = Entree(nom, numero);
    }
    else
    {
        std::cout << "Tableau plein. Impossible d'ajouter une nouvelle entrée." << std::endl;
    }
}

void Tableau::Supprimer(std::string nom, std::string numero)
{
    for (int i = 0; i < this->nbelem; i++)
    {
        if (this->entrees[i].Nom == nom && this->entrees[i].NumeroTelephone == numero)
        {
            for (int j = i; j < this->nbelem - 1; j++)
            {
                this->entrees[j] = this->entrees[j + 1];
            }
            this->nbelem--;
            break;
        }
    }
}

void Tableau::Supprimer(std::string nom)
{
    for (int i = 0; i < this->nbelem; i++)
    {
        if (this->entrees[i].Nom == nom)
        {
            for (int j = i; j < this->nbelem - 1; j++)
            {
                this->entrees[j] = this->entrees[j + 1];
            }
            this->nbelem--;
            i--;
        }
    }
}

int Tableau::GetNbElem()
{
    return this->nbelem;
}

int Tableau::GetTaille()
{
    return this->tailleTotale;
}

std::ostream &operator<<(std::ostream &out, Tableau &tableau)
{
    for (int i = 0; i < tableau.nbelem; i++)
    {
        out << "Entrée " << i + 1 << ":" << std::endl;
        out << tableau.entrees[i] << std::endl;
    }
    return out;
}

bool Tableau::operator==(Tableau &autre)
{
    if (nbelem != autre.nbelem)
    {
        return false;
    }

    for (int i = 0; i < nbelem; i++)
    {
        if (entrees[i] != autre.entrees[i])
        {
            return false;
        }
    }

    return true;
}

Tableau Tableau::operator+(Tableau &autre)
{
    Tableau resultat(tailleTotale + autre.tailleTotale);
    for (int i = 0; i < nbelem; i++)
    {
        resultat.Ajouter(entrees[i].Nom, entrees[i].NumeroTelephone);
    }
    for (int i = 0; i < autre.nbelem; i++)
    {
        resultat.Ajouter(autre.entrees[i].Nom, autre.entrees[i].NumeroTelephone);
    }
    return resultat;
}

Tableau &Tableau::operator+=(Tableau &autre)
{
    for (int i = 0; i < autre.nbelem; i++)
    {
        Ajouter(autre.entrees[i].Nom, autre.entrees[i].NumeroTelephone);
    }
    return *this;
}

Entree &Tableau::operator[](std::string nom)
{
    for (int i = 0; i < nbelem; i++)
    {
        if (entrees[i].Nom == nom)
        {
            return entrees[i];
        }
    }
    Entree entreeVide("", "");
    return entreeVide;
}

bool Tableau::operator/(std::string nom)
{
    for (int i = 0; i < nbelem; i++)
    {
        if (entrees[i].Nom == nom)
        {
            return true;
        }
    }
    return false;
}