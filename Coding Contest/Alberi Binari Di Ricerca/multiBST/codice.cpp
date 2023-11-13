#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "bst.h"
using namespace std;
int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    string type = "";
    string visit = "";
    int n = 0;
    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n >> visit;
        if (type == "int")
        {
            BST<int> BstInt;
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

            if (visit == "preorder")
            {
                BstInt.preorder();
            }

            if (visit == "inorder")
            {
                BstInt.inorder();
            }

            if (visit == "postorder")
            {
                BstInt.postorder();
            }

            fileOutput << BstInt.print();
            fileOutput << "\n";
        }
        if (type == "double")
        {
            BST<double> BstDouble;
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

            if (visit == "preorder")
            {
                BstDouble.preorder();
            }

            if (visit == "inorder")
            {
                BstDouble.inorder();
            }

            if (visit == "postorder")
            {
                BstDouble.postorder();
            }

            fileOutput << BstDouble.print();
            fileOutput << "\n";
        }
    }
}