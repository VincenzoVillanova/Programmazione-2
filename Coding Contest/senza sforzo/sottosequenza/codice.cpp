#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0;
    string sottosequenza = "", s = "";
    for (int i = 0; i < 100; i++)
    {
        do
        {
            fileInput >> n >> sottosequenza;
            for (int j = 0; j < n; j++)
            {
                s="";
                fileInput >> s;

                if (s.find(sottosequenza) != string ::npos)
                {
                    fileOutput << s << " ";
                }
            }
            fileOutput << "\n";

        } while (fileInput.good());
    }
}