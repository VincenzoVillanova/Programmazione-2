#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;
int main()
{
    string type = "";
    int n = 0;

    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    // do
    //  {
    for (int i = 0; i < 100; i++)
    {
        BST<int> intBST;
        BST<double> doubleBST;

        fileInput >> type;
        fileInput >> n;
        for (int j = 0; j < n; j++)
        {
            string op;
            fileInput >> op;
            if (type == "int")
            {
                int value = stoi(op.substr(op.find(":") + 1));
                if (op.substr(0, op.find(":")) == "ins")
                    intBST.insert(value);

                else
                    intBST.remove(value);
            }
            else
            {
                double value = stod(op.substr(op.find(":") + 1));
                if (op.substr(0, op.find(":")) == "ins")
                    doubleBST.insert(value);
                else
                    doubleBST.remove(value);
            }
        }
        if (type == "int")
        {
            fileOutput << intBST.CalcolaFoglie() << "\n";
        }
        else
        {
            fileOutput << doubleBST.CalcolaFoglie() << "\n";
        }
    }
    // } while (fileInput.good());
}