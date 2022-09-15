#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int vec[], int dim)
{
    int indexMin;

    for (int c = 0; c < dim; c++)
    {
        indexMin = c;

        for (int i = c + 1; i < dim; i++)
        {
            if (vec[i] < vec[indexMin])
            {
                indexMin = i;
            }
        }

        swap(vec[c], vec[indexMin]);
    }
}

int main()
{
    int vec[10] = {10, 7, 5, 8, 2, 6, 4, 3, 1, 9};

    cout << "Array non ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]" << endl
         << endl;

    selectionSort(vec, 10);

    cout << "Array ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]";
}