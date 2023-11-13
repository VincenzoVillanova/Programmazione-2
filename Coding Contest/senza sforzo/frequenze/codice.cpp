#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort2(int vec[], char lettere[], int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (lettere[c] < lettere[i])
            {
                if (vec[c] == vec[i])
                {
                    swap(lettere[c], lettere[i]);
                }
            }
        }
    }
}

void BubbleSort(int vec[], char lettere[], int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {

            if (vec[c] < vec[i])
            {
                swap(vec[c], vec[i]);
                swap(lettere[c], lettere[i]);
            }
        }
    }
    BubbleSort2(vec, lettere, 26);
}

void BubbleSortl(char vec[], int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {

            if (vec[c] > vec[i])
            {
                swap(vec[c], vec[i]);
            }
        }
    }
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int cont = 0, dim = 0;
    char lettere[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int val[26];
    do
    {
        string s = "";
        string chars = " ";
        getline(fileInput, s);

        for (char c : chars)
        {
            s.erase(std::remove(s.begin(), s.end(), c), s.end());
        }

        string str = "", completa = s;
        BubbleSortl(lettere, 26);

        for (int i = 0; i < 26; i++)
        {
            val[i] = 0;
        }
        for (int i = 0; i < completa.length(); i++)
        {
            if (completa[i] == 'a')
            {
                val[0]++;
            }

            if (completa[i] == 'b')
            {
                val[1]++;
            }

            if (completa[i] == 'c')
            {
                val[2]++;
            }

            if (completa[i] == 'd')
            {
                val[3]++;
            }

            if (completa[i] == 'e')
            {
                val[4]++;
            }

            if (completa[i] == 'f')
            {
                val[5]++;
            }

            if (completa[i] == 'g')
            {
                val[6]++;
            }

            if (completa[i] == 'h')
            {
                val[7]++;
            }

            if (completa[i] == 'i')
            {
                val[8]++;
            }

            if (completa[i] == 'j')
            {
                val[9]++;
            }

            if (completa[i] == 'k')
            {
                val[10]++;
            }

            if (completa[i] == 'l')
            {
                val[11]++;
            }

            if (completa[i] == 'm')
            {
                val[12]++;
            }

            if (completa[i] == 'n')
            {
                val[13]++;
            }

            if (completa[i] == 'o')
            {
                val[14]++;
            }

            if (completa[i] == 'p')
            {
                val[15]++;
            }

            if (completa[i] == 'q')
            {
                val[16]++;
            }

            if (completa[i] == 'r')
            {
                val[17]++;
            }

            if (completa[i] == 's')
            {
                val[18]++;
            }

            if (completa[i] == 't')
            {
                val[19]++;
            }

            if (completa[i] == 'u')
            {
                val[20]++;
            }

            if (completa[i] == 'v')
            {
                val[21]++;
            }

            if (completa[i] == 'w')
            {
                val[22]++;
            }

            if (completa[i] == 'x')
            {
                val[23]++;
            }

            if (completa[i] == 'y')
            {
                val[24]++;
            }

            if (completa[i] == 'z')
            {
                val[25]++;
            }
        }

        BubbleSort(val, lettere, 26);

        for (int i = 0; i < 26; i++)
        {
            if (val[i] != 0)
            {
                fileOutput << lettere[i] << ":" <<val[i] << " ";
            }
        }
        fileOutput << "\n";

    } while (!fileInput.eof());
}