#include <iostream>
using namespace std;

bool RicercaLineare(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int vec[10] = {10, 7, 5, 8, 2, 6, 4, 3, 1, 9};

    cout << "Array = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]" << endl
         << endl;

    bool x = RicercaLineare(vec, 10, 3);
    bool y = RicercaLineare(vec, 10, 25);

    if (x)
    {
        cout << "Ho trovato il numero 3!" << endl;
    }
    else
    {
        cout << "NON ho trovato il numero 3!" << endl;
    }

    if (y)
    {
        cout << "Ho trovato il numero 25!" << endl;
    }
    else
    {
        cout << "NON ho trovato il numero 25!" << endl;
    }
}