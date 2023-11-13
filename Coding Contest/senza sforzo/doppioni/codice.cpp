#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0;
    do
    {
        int cont = 0;
        fileInput >> n;
        int val[n];
        for (int j = 0; j < n; j++)
        {

            fileInput >> val[j];
        }
        for (int z = 0; z < n; z++)
        {
            for (int x = 0; x < n; x++)
            {
                if (val[z] == val[x] && z != x && val[z] != 0 && val[x]!=0)
                {
                    cont++;
                    val[x]=0;
                }
            }
        }
        fileOutput << cont;
        fileOutput << "\n";
        cont=0;

    } while (fileInput.good());
}