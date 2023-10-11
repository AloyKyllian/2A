class Compte
{
private:
    // variables cachées appelées “attributs”
    // accessibles depuis les méthodes de la classe
protected:
    float solde;
    // variables accessibles depuis la classe et ses sous-classes
public:
    Compte();
    void depot(float depot);
    void retrait(float retrait);
    void afficher_solde();
    float getSolde();
    void virement(Compte &compte, float argent);
    // fonctions qui manipulent les variables cachées
    // appelées “méthodes”
};