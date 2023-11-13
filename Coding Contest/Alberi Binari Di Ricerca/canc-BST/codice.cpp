#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;
int main()
{
    BST <int> BstInt;
    BST <double> BstDouble;
    string output = "";
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string type = "";
    string s = "";
    string stri = "";
    int n = 0;
    string visual = "";
    int vala = 0;
    int al = 0;
    double vald = 0;
    double ald = 0.0;
    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n >> visual;
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
            if (visual == "preorder")
            {
                BstInt.preorder();
                stri = BstInt.Ritornas();
                fileOutput << stri;
                BstInt.Puliscis();
            }
            if (visual == "inorder")
            {
                BstInt.inorder();
                stri = BstInt.Ritornas();
                fileOutput << stri;
                BstInt.Puliscis();
            }
            if (visual == "postorder")
            {
                BstInt.postorder();
                stri = BstInt.Ritornas();
                fileOutput << stri;
                BstInt.Puliscis();
            }
            fileOutput << "\n";
            cout << endl;
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

            if (visual == "preorder")
            {
                BstDouble.preorder();
                stri = BstDouble.Ritornas();
                fileOutput << stri;
                BstDouble.Puliscis();
            }

            if (visual == "inorder")
            {
                BstDouble.inorder();
                stri = BstDouble.Ritornas();
                fileOutput << stri;
                BstDouble.Puliscis();
            }
            if (visual == "postorder")
            {
                BstDouble.postorder();
                stri = BstDouble.Ritornas();
                fileOutput << stri;
                BstDouble.Puliscis();
            }
            fileOutput << "\n";
            cout << endl;
            BstDouble.clear();
        }
    }
}