#include <string>
#include <iostream>
using namespace std;

class Livre
{
private:
    std::string titre;
    int annee;

public:
    Livre(std::string = "", int = 2000); // constructeur normal + sans parametre
    Livre(Livre &);
    ~Livre();
    friend ostream &operator<<(ostream &out, Livre &l);
};