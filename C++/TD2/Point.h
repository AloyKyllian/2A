#include "Base.cpp"

class Point : public Base
{
    int x, y;

public:
    Point(int, int);
    void AfficherPoint();
};