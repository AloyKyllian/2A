class Base
{
public:
    vitual void afficher() = 0;
    virtual bool operator==(Base *) = 0;
    virtual Base *clone() = 0;
};
class Point : public Base
{
    int x, y;

public:
    Point(int, int);
    void afficher();
}