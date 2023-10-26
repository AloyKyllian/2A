#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y) : x(x), y(y)
{
}

void Point::AfficherPoint()
{
    cout << "x " << this->x;
    cout << "   y " << this->y;
}

bool Point ::operator==(Point &p2)
{
    if (this->x == p2.x && this->y == p2.y)
        return true;
    return false;
}
