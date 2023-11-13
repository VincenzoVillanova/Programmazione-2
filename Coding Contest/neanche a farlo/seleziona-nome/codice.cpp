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
        char a = ' ', b = ' ';
        string nome_1 = "", nome_2 = "", nome_3 = "";
        int n1 = 0, n2 = 0, n3 = 0;
        fileInput >> a >> b >> n1 >> nome_1 >> n2 >> nome_2 >> n3 >> nome_3;

        if (nome_1[0] == a || nome_1[n1 - 1] == a)
        {

            if (nome_1[0] != b && nome_1[n1 - 1] != b)
            {
                fileOutput << nome_1<<" ";
            }
        }

        if (nome_2[0] == a || nome_2[n2 - 1] == a)
        {

            if (nome_2[0] != b && nome_2[n2 - 1] != b)
            {
                fileOutput << nome_2<<" ";
            }
        }
        
        if (nome_3[0] == a || nome_3[n3 - 1] == a)
        {

            if (nome_3[0] != b && nome_3[n3 - 1] != b)
            {
                fileOutput << nome_3<<" ";
            }
        }
        fileOutput<< "\n";
        
    }
}
