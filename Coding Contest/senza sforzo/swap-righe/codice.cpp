#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void print(int *arr, int n)
{
    cout << "[ ";

    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void print(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

int *getArraySomma(int **arr, int n, int m)
{
    int *somma;
    somma = new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            somma[i] += arr[i][j];
        }
    }

    return somma;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int bubbleSort(int vec[], int dim)
{
    int cont = 0;
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (vec[c] > vec[i])
            {
                cont++;
                swap(vec[c], vec[i]);
            }
        }
    }

    return cont;
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int num = 0, r = 0, c = 0, ris = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> r >> c;
        int **mat, *somma;

        mat = new int *[r];
        somma = new int[r];
        for (int i = 0; i < r; i++)
        {
            mat[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                fileInput >> num;
                mat[i][j] = num;
            }
        }

        print(mat, r, c);
        somma = getArraySomma(mat, r, c);
        print(somma, r);

        int ris = bubbleSort(somma, r);
        print(somma, r);

        fileOutput << ris << endl;
    }
}