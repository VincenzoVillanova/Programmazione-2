#ifndef FILE_H
#define FILE_H

#include <iostream>
using namespace std;

class Film
{
private:
    string nome;
    int anno;
    double valutazione;

public:
    Film(string nome, int anno, double valutazione) : nome(nome), anno(anno), valutazione(valutazione) {}

    friend bool operator<(Film, Film);
    friend bool operator<=(Film, Film);
    friend bool operator>(Film, Film);
    friend bool operator>=(Film, Film);

    ostream &put(ostream &os)
    {
        os << "Nome: " << nome;
        os << "\nAnno: " << anno;
        os << "\nValutazione: " << valutazione;

        return os;
    }
};

ostream &operator<<(ostream &os, Film &obj)
{
    return obj.put(os);
}

bool operator<(Film a, Film b)
{
    if (a.valutazione < b.valutazione)
    {
        return true;
    }

    return false;
}

bool operator>(Film a, Film b)
{
    if (a.valutazione > b.valutazione)
    {
        return true;
    }

    return false;
}

bool operator>=(Film a, Film b)
{
    if (a.valutazione >= b.valutazione)
    {
        return true;
    }

    return false;
}

bool operator<=(Film a, Film b)
{
    if (a.valutazione <= b.valutazione)
    {
        return true;
    }

    return false;
}

#endif