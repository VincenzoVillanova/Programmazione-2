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
            int lun=nome.length()/2;
            string s=nome.substr(0,lun);
            fileOutput << s << " ";
            fileOutput << "\n";
    }
}
