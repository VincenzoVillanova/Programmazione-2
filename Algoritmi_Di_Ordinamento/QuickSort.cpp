#include <iostream>
using namespace std;

/*
 *
 *  p = indice iniziale sottoarray
 *  i = p - 1
 *  j = p
 *  r = indice finale sottoarray
 *
 *  Far scorrere j da p ad r-1, se l'elemento A[j] < pivot
 *  allora faccio avanzare e scambio A[i] ed A[j]
 *  alla fine scambio il pivot con A[i+1]
 *
 */

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int vec[], int p, int q)
{
    int pivot = vec[q]; // pivot
    int i = (p - 1);

    for (int j = p; j <= q - 1; j++)
    {
        if (vec[j] < pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[q]);

    return (i + 1);
}

void quickSort(int vec[], int p, int r)
{
    int q = 0;

    if (p < r)
    {
        q = partition(vec, p, r);
    }
    else
    {
        return;
    }

    quickSort(vec, p, q - 1);
    quickSort(vec, q + 1, r);
}

int main()
{
    int vec[10] = {10, 7, 5, 8, 2, 6, 4, 3, 1, 9};

    cout << "array non ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]" << endl
         << endl;

    quickSort(vec, 0, 9);

    cout << "array ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]";
}