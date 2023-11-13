#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "bst.h"
using namespace std;
int main()
{

    BST<int> BstInt;
    BST<double> BstDouble;
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    string type = "";
    int n = 0;
    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n;
        if (type == "int")
        {
            int val[n];
            for (int i = 0; i < n; i++)
            {
                string s = "";
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
            int valor1 = 0, valor2 = 0;
            fileInput >> valor1 >> valor2;
            if (valor1 >= valor2)
            {
                cout<<BstInt.Predecessore(valor1, valor2)<< endl;
                fileOutput << BstInt.Predecessore(valor1, valor2);
            }
            else
            {
                 cout <<BstInt.Predecessore(valor2, valor1)<< endl;
                fileOutput << BstInt.Predecessore(valor2, valor1);
            }
            fileOutput << "\n";
            BstInt.clear();
        }
        if (type == "double")
        {
            double val[n];
            for (int i = 0; i < n; i++)
            {
                string s = "";
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
            double valord1 = 0, valord2 = 0;
            fileInput >> valord1 >> valord2;
            if (valord1 >= valord2)
            {
                cout << BstDouble.Predecessore(valord1, valord2) << endl;
                fileOutput << BstDouble.Predecessore(valord1, valord2);
            }
            else
            {
                cout << BstDouble.Predecessore(valord2, valord1) << endl;
                fileOutput << BstDouble.Predecessore(valord2, valord1);
            }
            fileOutput << "\n";
            BstDouble.clear();
        }
    }
}