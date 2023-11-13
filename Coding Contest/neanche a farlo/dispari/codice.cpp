#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0;
    int numero = 0;
    for (int i = 0; i < 100; i++)
    {
        do
        {
            fileInput >> n;
            int numero = 0;
            for (int j = 0; j < n; j++)
            {
                fileInput >> numero;
                if (numero % 2 != 0)
                {
                     fileOutput << numero << " ";

                }
            }
            fileOutput << "\n";
            numero = 0;
        } while (fileInput.good());
    }
}
