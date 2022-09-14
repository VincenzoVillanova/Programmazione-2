#include <iostream>
using namespace std;

int RicercaBinaria(int v[], int basso, int alto, int chiave)
{
    int centrale;
    int valoreCentrale;
    while (basso <= alto)
    {
        centrale = (basso + alto) / 2;
        valoreCentrale = v[centrale];

        if (chiave == valoreCentrale)
        {
            return centrale;
        }

        else if (chiave < valoreCentrale)
        {
            alto = centrale - 1;
        }
        else
        {
            basso = centrale + 1;
        }
    }

    return -1;
}

int main()
{
    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]" << endl
         << endl;

    int x = RicercaBinaria(vec, 0, 10, 3);
    int y = RicercaBinaria(vec, 0, 10, 25);

    if (x >= 0)
    {
        cout << "Ho trovato il numero 3!" << endl;
    }
    else
    {
        cout << "NON ho trovato il numero 3!" << endl;
    }

    if (y >= 0)
    {
        cout << "Ho trovato il numero 25!" << endl;
    }
    else
    {
        cout << "NON ho trovato il numero 25!" << endl;
    }
}