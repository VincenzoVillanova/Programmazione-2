#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string inversa(string s)
{
    string p = "";
    int cont = 0;
    for (int i = 0; i < s.length(); i++)
    {
        p = s[i] + p;
    }
    return p;
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 3;
    int c=0;
    do
    {
        string s = "";
        fileInput >> c;

        for (int i = 0; i < n; i++)
        {
            fileInput >> s;
            string g = inversa(s);
            fileOutput << g << " ";
        }
        fileOutput << "\n";

    } while (fileInput.good());
}