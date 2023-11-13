#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0, x = 0;
    int cont = 0;
    for (int i = 0; i < 100; i++)
    {
        do
        {
            fileInput >> n >> x;
            int numeri[n];
            for (int j = 0; j < n; j++)
            {
                fileInput >> numeri[j];
                if (numeri[j]>x)
                {
                    cont++;
                }
            }
            fileOutput <<cont<<" ";
             for (int j = 0; j < n; j++)
            {
                if (numeri[j]>x)
                {
                    fileOutput <<numeri[j]<<" ";
                }
            }
            fileOutput << "\n";
            cont=0;
        } while (fileInput.good());
    }
}
