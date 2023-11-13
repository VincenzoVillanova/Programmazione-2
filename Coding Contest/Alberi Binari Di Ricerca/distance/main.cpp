#include <iostream>
#include <string>
#include <fstream>
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
                string s="";
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
            int vali1 = 0, vali2 = 0;
            fileInput >> vali1 >> vali2;
            cout<<vali1<<" "<<vali2<<endl;
            fileOutput << BstInt.distanzaChiavi(vali1,vali2);
            fileOutput << "\n";
            BstInt.clear();
        }
        if (type == "double")
        {
            double val[n];
            for (int i = 0; i < n; i++)
            {
                string s="";
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

            double vald1 = 0, vald2 = 0;
            fileInput >> vald1 >> vald2;
            fileOutput<<BstDouble.distanzaChiavi(vald1,vald2);
            fileOutput << "\n";
            BstDouble.clear();
        }
    }
}