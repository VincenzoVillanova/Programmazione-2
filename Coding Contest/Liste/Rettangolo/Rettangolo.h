#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include "lista.h"
#include <iostream>
using namespace std;

class Rettangolo
{
protected:
    int latomin;
    int latomax;
    double area;

    template <typename U>
    friend class Node;

public:
    Rettangolo(int latomin, int latomax) : latomin(latomin), latomax(latomax)
    {
        area = latomax * latomin;
    }

    friend bool operator<(Rettangolo, Rettangolo);
    friend bool operator<=(Rettangolo, Rettangolo);
    friend bool operator>(Rettangolo, Rettangolo);
    friend bool operator>=(Rettangolo, Rettangolo);
    friend bool operator==(Rettangolo, Rettangolo);
    friend bool operator!=(Rettangolo, Rettangolo);

    double getArea()
    {
        return this->area;
    }

    ostream &put(ostream &os)
    {
        os << "\nlato minore: " << latomin;
        os << "\nlato maggiore: " << latomax;
        os << "\narea: " << area << endl;
        os << "----------";
        return os;
    }
};

ostream &operator<<(ostream &os, Rettangolo &obj)
{
    return obj.put(os);
}

bool operator<(Rettangolo a, Rettangolo b)
{
    if (a.area < b.area)
    {
        return true;
    }

    return false;
}

bool operator>(Rettangolo a, Rettangolo b)
{
    if (a.area > b.area)
    {
        return true;
    }

    return false;
}

bool operator>=(Rettangolo a, Rettangolo b)
{
    if (a.area >= b.area)
    {
        return true;
    }

    return false;
}

bool operator==(Rettangolo a, Rettangolo b)
{
    if (a.area == b.area)
    {
        return true;
    }

    return false;
}

bool operator!=(Rettangolo a, Rettangolo b)
{
    if (a.area != b.area)
    {
        return true;
    }

    return false;
}

bool operator<=(Rettangolo a, Rettangolo b)
{
    if (a.area <= b.area)
    {
        return true;
    }

    return false;
}
#endif