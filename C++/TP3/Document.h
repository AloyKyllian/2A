#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <iostream>

class Document
{
public:
    Document(std::string &t, std::string resume = "", std::string auteur = "");
    Document(const Document &other);
    ~Document();

    void afficher() const;
    Document clone() const;
    Document &operator=(const Document &other);

protected:
    std::string &titre;
    std::string *resume;
    std::string auteur;
};

#endif // DOCUMENT_H
