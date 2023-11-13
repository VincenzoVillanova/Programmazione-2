#include <iostream>
#include "lista.h"
#include "Rettangolo.h"

int main()
{
    List<Rettangolo> lista;
    Rettangolo *aux;
    int min = 0, max = 180;

    aux = new Rettangolo(5, 10);
    lista.insertTail(*aux);

    aux = new Rettangolo(20, 40);
    lista.insertTail(*aux);

    aux = new Rettangolo(13, 15);
    lista.insertTail(*aux);

    aux = new Rettangolo(4, 8);
    lista.insertTail(*aux);
    cout << "----------";
    lista.PulisciListaArea(min, max);
    cout << lista << endl;
}