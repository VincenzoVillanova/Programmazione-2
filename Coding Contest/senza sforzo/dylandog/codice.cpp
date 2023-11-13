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
        int cont = 0, lib = 0;
        fileInput >> n >> lib;
        int val[n];
        bool cond = false;
        for (int j = 0; j < n; j++)
        {
            fileInput >> val[j];
        }
        for (int j = 0; j < n; j++)
        {

            if (val[j] == lib)
            {
                fileOutput << ++j;
                fileOutput << "\n";
                cond = true;
            }
        }
        if (cond == false)
        {
            fileOutput << "0";
            fileOutput << "\n";
        }

    } while (fileInput.good());
}