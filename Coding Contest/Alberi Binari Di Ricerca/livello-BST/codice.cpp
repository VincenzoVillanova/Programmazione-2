#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;
int main()
{
    BST<int> BstInt;
    BST<double> BstDouble;
    string output = "";
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string type = "";
    string s = "";
    int n = 0;
    int na = 0;
    int vala = 0;
    int al = 0;
    double vald = 0;
    for(int x=0;x<100;x++)
    {
        fileInput >> type >> n >> na;
        if (type == "int")
        {
            int val[n];
            for (int i = 0; i < n; i++)
            {
                fileInput >> s;
                if (s[0] == 'i') // Inserimento
                {
                    val[i] = stoi(s.substr(4, s.length()));
                    BstInt.insert(val[i]);
                }
                else if (s[0] == 'c') // Cancellazione
                {
                    val[i] = stoi(s.substr(5, s.length()));
                    BstInt.remove(val[i]);
                }
            }
            for (int i = 0; i < na; i++)
            {
                fileInput >> vala;
                int al = BstInt.getAltezza(vala);

                fileOutput << al << " ";
            }

            fileOutput << "\n";
            BstInt.clear();
        }
        if (type == "double")
        {
            double val[n];
            for (int i = 0; i < n; i++)
            {
                fileInput >> s;
                if (s[0] == 'i') // Inserimento
                {
                    val[i] = stod(s.substr(4, s.length()));
                    BstDouble.insert(val[i]);
                }
                else if (s[0] == 'c') // Cancellazione
                {
                    val[i] = stod(s.substr(5, s.length()));
                    BstDouble.remove(val[i]);
                }
            }

            for (int i = 0; i < na; i++)
            {
                fileInput >> vald;

                int al = BstDouble.getAltezza(vald);

                fileOutput << al << " ";
            }

            fileOutput << "\n";
            BstDouble.clear();
        }
    }
}