#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    for (int i = 0; i < 100; i++)
    {
        string nome = "";
        fileInput >> nome;

            fileOutput << nome<<nome << " ";
            fileOutput << "\n";
        
    }
}
