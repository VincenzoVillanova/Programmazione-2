#include <iostream>
#include <cmath>
using namespace std;

/*
 *
 *  p = indice iniziale sottoArray
 *  q = indice p <= q <= r
 *  r = indice finale sottoArray
 *
 *  n1 = q - p + 1
 *  n2 = r - q
 *
 *  Creo due A L e Q con rispettiva dimensione n1 ed n2
 *
 *  L <- A[p -> q]
 *  R <- A[q -> r]
 *
 *  k, i, j indici che scorrono rispettivamente A, L ed R
 *
 */

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1],
        *R = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + 1 + j];
    }

    int indiceL = 0,
        indiceR = 0,
        indiceA = p;

    while (indiceL < n1 && indiceR < n2)
    {
        if (L[indiceL] <= R[indiceR])
        {
            A[indiceA] = L[indiceL];
            indiceL++;
        }
        else
        {
            A[indiceA] = R[indiceR];
            indiceR++;
        }

        indiceA++;
    }

    while (indiceL < n1)
    {
        A[indiceA] = L[indiceL];
        indiceL++;
        indiceA++;
    }

    while (indiceR < n2)
    {
        A[indiceA] = R[indiceR];
        indiceR++;
        indiceA++;
    }
}

void mergeSort(int vec[], int p, int r)
{
    int q = 0;

    if (p < r)
    {
        q = floor((p + r) / 2);
    }
    else
    {
        return;
    }

    mergeSort(vec, p, q);
    mergeSort(vec, q + 1, r);

    merge(vec, p, q, r);
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

    mergeSort(vec, 0, 9);

    cout << "Array ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]";
}