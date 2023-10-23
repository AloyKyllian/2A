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
