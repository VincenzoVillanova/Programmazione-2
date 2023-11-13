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

        if (nome.length() % 2 == 0)
        {
            fileOutput << nome << " ";
            fileOutput << "\n";
        }else{
            nome[nome.length()-1]=' ';
            fileOutput << nome << " ";
            fileOutput << "\n";
        }
    }
}
