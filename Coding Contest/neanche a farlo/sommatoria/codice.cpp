#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0;
    double sommatoria = 0;
    for (int i = 0; i < 100; i++)
    {
        do
        {
            fileInput >> n;
            double val = 0;
            for (int j = 0; j < n; j++)
            {
                fileInput >> val;
                sommatoria += val;
            }
            fileOutput << sommatoria << " ";
            fileOutput << "\n";
            sommatoria=0;
        } while (fileInput.good());
    }
}
