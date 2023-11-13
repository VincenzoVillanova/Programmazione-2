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
    int n = 0, mol = 0;
    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n >> mol;
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
            for (int k = 0; k < mol; k++)
            {
                int valoreimportante = 0, esito = 0;
                fileInput >> valoreimportante;
                esito = BstInt.stepsuccessor(valoreimportante);
                if (esito == -1)
                {
                    fileOutput << "INF ";
                }
                else
                {
                    fileOutput << esito << " ";
                }
            }
            fileOutput << endl;
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
            for (int k = 0; k < mol; k++)
            {
                double valoreimportante = 0;
                int esito = 0;
                fileInput >> valoreimportante;
                esito = BstDouble.stepsuccessor(valoreimportante);
                if (esito == -1)
                {
                    fileOutput << "INF ";
                }
                else
                {
                    fileOutput << esito << " ";
                }
            }
            fileOutput << endl;
            BstDouble.clear();
    }
}
}