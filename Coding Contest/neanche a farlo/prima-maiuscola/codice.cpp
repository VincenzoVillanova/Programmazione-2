#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    string output;
    for (int i = 0; i < 100; i++)
    {
        string nome_1 = "", nome_2 = "", nome_3 = "";
        int n1 = 0, n2 = 0, n3 = 0;
        fileInput >> n1 >> nome_1 >> n2 >> nome_2 >> n3 >> nome_3;

        nome_1[0]=toupper(nome_1[0]);
        nome_2[0]=toupper(nome_2[0]);
        nome_3[0]=toupper(nome_3[0]);
        
        fileOutput << nome_1 << " " << nome_2<< " " << nome_3<< "\n";
    }
}
