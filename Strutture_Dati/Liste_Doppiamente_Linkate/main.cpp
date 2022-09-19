#include <iostream>
#include "dllist.h"

int main()
{
    DLList<int> lista, lista2;

    lista.insertHead(2);
    lista.insertHead(5);
    lista.insertHead(7);

    lista2.insertTail(2);
    lista2.insertTail(5);
    lista2.insertTail(7);

    std::cout << lista << std::endl;
    std::cout << lista2 << std::endl;

    lista.removeHead();
    lista2.removeTail();

    std::cout << lista << std::endl;
    std::cout << lista2 << std::endl;
}