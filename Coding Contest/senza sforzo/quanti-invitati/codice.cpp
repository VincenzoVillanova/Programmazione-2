#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int cont = 0;
    string s;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        cont = 0;
        getline(fileInput, s);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                cont++;
            }
        }

        fileOutput << cont + 1 << endl;
    }
}