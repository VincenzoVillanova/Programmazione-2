#include <iostream>
using namespace std;

void insertionSort(int vec[], int dim)
{
    int temp = 0, j = 0;

    for (int i = 0; i < dim; i++)
    {
        temp = vec[i];

        for (j = i; j > 0; j--)
        {
            if (temp < vec[j - 1])
            {
                vec[j] = vec[j - 1];
            }
            else
            {
                break;
            }
        }

        vec[j] = temp;
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

    insertionSort(vec, 10);

    cout << "Array ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]";
}