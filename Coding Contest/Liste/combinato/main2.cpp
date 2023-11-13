#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    string output;
    for (int x = 0; x < 100; x++)
    {
        int n = 0;
        fileInput >> n;

        for (int i = 0; i < n; i++)
        {
            int val = 0;
            fileInput >> val;
        }
    }
}
